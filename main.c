#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {
    TOKEN_CONST, TOKEN_POW, TOKEN_MOD_ASSIGN,
    TOKEN_EOF, TOKEN_PRINT, TOKEN_LET, TOKEN_IDENT, TOKEN_INT, TOKEN_FLOAT, TOKEN_STRING,
    TOKEN_TRUE, TOKEN_FALSE,
    TOKEN_PLUS, TOKEN_MINUS, TOKEN_STAR, TOKEN_SLASH, TOKEN_MOD,
    TOKEN_PLUS_ASSIGN, TOKEN_MINUS_ASSIGN, TOKEN_STAR_ASSIGN, TOKEN_SLASH_ASSIGN,
    TOKEN_ASSIGN, TOKEN_AND, TOKEN_OR, TOKEN_NOT,
    TOKEN_IF, TOKEN_ELSE, TOKEN_WHILE, TOKEN_LPAREN, TOKEN_RPAREN,
    TOKEN_LBRACE, TOKEN_RBRACE, TOKEN_GT, TOKEN_LT, TOKEN_EQ, TOKEN_NEQ, TOKEN_INPUT,
    TOKEN_LBRACKET, TOKEN_RBRACKET, TOKEN_COMMA,
    TOKEN_ELIF, TOKEN_FOR, TOKEN_BREAK, TOKEN_CONTINUE, TOKEN_SWITCH, TOKEN_CASE, TOKEN_DEFAULT,
    TOKEN_FN, TOKEN_RETURN
} TokenType;

typedef struct { TokenType type; char value[256]; } Token;

char *src;
int src_pos = 0, src_len = 0;
Token tokens[10000];
int tokenCount = 0, currentTokenIndex = 0;

char declared_vars[1000][50];
int declared_count = 0;

FILE *out_funcs, *out_main;

int is_declared(const char* name) {
    for (int i = 0; i < declared_count; i++) {
        if (strcmp(declared_vars[i], name) == 0) return 1;
    }
    return 0;
}

void declare_var(const char* name) {
    strcpy(declared_vars[declared_count++], name);
}

void tokenize() {
    while (src_pos < src_len) {
        char c = src[src_pos];
        if (isspace(c)) { src_pos++; continue; }
        
        if (c == '|' && src_pos + 2 < src_len && src[src_pos+1] == '|' && src[src_pos+2] == '|') {
            src_pos += 3;
            while (src_pos < src_len && !(src[src_pos] == '|' && src[src_pos+1] == '|' && src[src_pos+2] == '|')) {
                src_pos++;
            }
            src_pos += 3;
            continue;
        }

        if (c == '|' && src_pos + 1 < src_len && src[src_pos+1] == '|') {
            src_pos += 2;
            while (src_pos < src_len && !(src[src_pos] == '|' && src[src_pos+1] == '|')) src_pos++;
            src_pos += 2;
            continue;
        }

        if (c == '"') {
            src_pos++;
            int t_idx = 0;
            Token t; t.type = TOKEN_STRING;
            while (src_pos < src_len && src[src_pos] != '"') {
                t.value[t_idx++] = src[src_pos++];
            }
            t.value[t_idx] = '\0';
            tokens[tokenCount++] = t; src_pos++; continue;
        }
        
        if (isdigit(c)) {
            int start = src_pos;
            int has_dot = 0;
            while (src_pos < src_len && (isdigit(src[src_pos]) || src[src_pos] == '.')) {
                if (src[src_pos] == '.') has_dot = 1;
                src_pos++;
            }
            Token t; t.type = has_dot ? TOKEN_FLOAT : TOKEN_INT;
            int len = src_pos - start; strncpy(t.value, &src[start], len); t.value[len] = '\0';
            tokens[tokenCount++] = t; continue;
        }
        if (isalpha(c) || c == '_') {
            int start = src_pos;
            while (src_pos < src_len && (isalnum(src[src_pos]) || src[src_pos] == '_')) src_pos++;
            Token t;
            int len = src_pos - start; strncpy(t.value, &src[start], len); t.value[len] = '\0';
            if (strcmp(t.value, "print") == 0) t.type = TOKEN_PRINT;
            else if (strcmp(t.value, "let") == 0) t.type = TOKEN_LET;
            else if (strcmp(t.value, "if") == 0) t.type = TOKEN_IF;
            else if (strcmp(t.value, "else") == 0) t.type = TOKEN_ELSE;
            else if (strcmp(t.value, "elif") == 0) t.type = TOKEN_ELIF;
            else if (strcmp(t.value, "while") == 0) t.type = TOKEN_WHILE;
            else if (strcmp(t.value, "for") == 0) t.type = TOKEN_FOR;
            else if (strcmp(t.value, "break") == 0) t.type = TOKEN_BREAK;
            else if (strcmp(t.value, "continue") == 0) t.type = TOKEN_CONTINUE;
            else if (strcmp(t.value, "switch") == 0) t.type = TOKEN_SWITCH;
            else if (strcmp(t.value, "case") == 0) t.type = TOKEN_CASE;
            else if (strcmp(t.value, "default") == 0) t.type = TOKEN_DEFAULT;
            else if (strcmp(t.value, "fn") == 0) t.type = TOKEN_FN;
            else if (strcmp(t.value, "return") == 0) t.type = TOKEN_RETURN;
            else if (strcmp(t.value, "input") == 0) t.type = TOKEN_INPUT;
            else if (strcmp(t.value, "true") == 0) { t.type = TOKEN_TRUE; strcpy(t.value, "1"); }
            else if (strcmp(t.value, "false") == 0) { t.type = TOKEN_FALSE; strcpy(t.value, "0"); }
            else if (strcmp(t.value, "or") == 0) { t.type = TOKEN_OR; strcpy(t.value, "||"); }
            else if (strcmp(t.value, "and") == 0) { t.type = TOKEN_AND; strcpy(t.value, "&&"); }
            else t.type = TOKEN_IDENT;
            tokens[tokenCount++] = t; continue;
        }
        
        Token t; t.value[0] = c; t.value[1] = '\0';
        if (c == '+') {
            if (src_pos + 1 < src_len && src[src_pos + 1] == '=') { t.type = TOKEN_PLUS_ASSIGN; strcpy(t.value, "+="); src_pos++; }
            else t.type = TOKEN_PLUS;
        } else if (c == '-') {
            if (src_pos + 1 < src_len && src[src_pos + 1] == '=') { t.type = TOKEN_MINUS_ASSIGN; strcpy(t.value, "-="); src_pos++; }
            else t.type = TOKEN_MINUS;
        } else if (c == '*') {
            if (src_pos + 1 < src_len && src[src_pos + 1] == '=') { t.type = TOKEN_STAR_ASSIGN; strcpy(t.value, "*="); src_pos++; }
            else t.type = TOKEN_STAR;
        } else if (c == '/') {
            if (src_pos + 1 < src_len && src[src_pos + 1] == '=') { t.type = TOKEN_SLASH_ASSIGN; strcpy(t.value, "/="); src_pos++; }
            else t.type = TOKEN_SLASH;
        } else if (c == '%') {
            t.type = TOKEN_MOD;
        } else if (c == '&') {
            if (src_pos + 1 < src_len && src[src_pos + 1] == '&') { t.type = TOKEN_AND; strcpy(t.value, "&&"); src_pos++; }
            else { src_pos++; continue; }
        } else if (c == '!') {
            if (src_pos + 1 < src_len && src[src_pos + 1] == '=') { t.type = TOKEN_NEQ; strcpy(t.value, "!="); src_pos++; }
            else { t.type = TOKEN_NOT; }
        } else if (c == '(') t.type = TOKEN_LPAREN; else if (c == ')') t.type = TOKEN_RPAREN;
        else if (c == '{') t.type = TOKEN_LBRACE; else if (c == '}') t.type = TOKEN_RBRACE;
        else if (c == '[') t.type = TOKEN_LBRACKET; else if (c == ']') t.type = TOKEN_RBRACKET;
        else if (c == ',') t.type = TOKEN_COMMA;
        else if (c == '>') t.type = TOKEN_GT; else if (c == '<') t.type = TOKEN_LT;
        else if (c == '=') {
            if (src_pos + 1 < src_len && src[src_pos + 1] == '=') { t.type = TOKEN_EQ; strcpy(t.value, "=="); src_pos++; }
            else t.type = TOKEN_ASSIGN;
        } else { src_pos++; continue; }
        tokens[tokenCount++] = t; src_pos++;
    }
    Token eof; eof.type = TOKEN_EOF; strcpy(eof.value, "EOF"); tokens[tokenCount++] = eof;
}

Token peek_token() { return (currentTokenIndex >= tokenCount) ? tokens[tokenCount - 1] : tokens[currentTokenIndex]; }
Token next_token() { Token t = peek_token(); if (currentTokenIndex < tokenCount) currentTokenIndex++; return t; }

void compile_expression(FILE* out) {
    while (1) {
        Token t = peek_token();
        if (t.type == TOKEN_INT || t.type == TOKEN_FLOAT || t.type == TOKEN_IDENT || 
            t.type == TOKEN_TRUE || t.type == TOKEN_FALSE ||
            t.type == TOKEN_PLUS || t.type == TOKEN_MINUS || 
            t.type == TOKEN_STAR || t.type == TOKEN_SLASH || t.type == TOKEN_MOD ||
            t.type == TOKEN_AND || t.type == TOKEN_OR || t.type == TOKEN_NOT ||
            t.type == TOKEN_LPAREN || t.type == TOKEN_RPAREN || t.type == TOKEN_COMMA ||
            t.type == TOKEN_GT || t.type == TOKEN_LT || t.type == TOKEN_EQ || t.type == TOKEN_NEQ) {
            fprintf(out, "%s ", next_token().value);
        } else {
            break;
        }
    }
}

void compile_condition(FILE* out) {
    int depth = 0;
    next_token();
    while (currentTokenIndex < tokenCount) {
        Token t = peek_token();
        if (t.type == TOKEN_LPAREN) depth++;
        else if (t.type == TOKEN_RPAREN) {
            if (depth == 0) {
                next_token();
                break;
            }
            depth--;
        }
        fprintf(out, "%s ", next_token().value);
    }
}

void compile_block(FILE* out);

void compile_statement(FILE* out) {
    Token tok = next_token();
    if (tok.type == TOKEN_FN) {
        int saved_count = declared_count;
        declared_count = 0;
        
        Token name = next_token();
        fprintf(out_funcs, "double %s(", name.value);
        next_token();
        int first = 1;
        while (peek_token().type != TOKEN_RPAREN) {
            if (!first) { fprintf(out_funcs, ", "); next_token(); }
            Token param = next_token();
            fprintf(out_funcs, "double %s", param.value);
            declare_var(param.value);
            first = 0;
        }
        next_token();
        fprintf(out_funcs, ") {\n");
        next_token();
        
        while (currentTokenIndex < tokenCount) {
            Token t = peek_token();
            if (t.type == TOKEN_RBRACE) { next_token(); break; }
            if (t.type == TOKEN_EOF) break;
            compile_statement(out_funcs);
        }
        fprintf(out_funcs, "return 0;\n}\n");
        
        declared_count = saved_count;
        return;
    } else if (tok.type == TOKEN_RETURN) {
        fprintf(out, "return ");
        compile_expression(out);
        fprintf(out, ";\n");
    } else if (tok.type == TOKEN_PRINT) {
        Token next = peek_token();
        if (next.type == TOKEN_STRING) {
            next_token();
            fprintf(out, "printf(\"%%s\\n\", \"%s\");\n", next.value);
        } else {
            fprintf(out, "printf(\"%%g\\n\", (double)(");
            compile_expression(out);
            fprintf(out, "));\n");
        }
    } else if (tok.type == TOKEN_LET) {
        Token name_tok = next_token();
        next_token();
        Token val_peek = peek_token();
        
        if (!is_declared(name_tok.value)) {
            if (val_peek.type == TOKEN_LBRACKET) {
                fprintf(out, "int %s[] = ", name_tok.value);
            } else if (val_peek.type == TOKEN_FLOAT) {
                fprintf(out, "double %s = ", name_tok.value);
            } else {
                fprintf(out, "int %s = ", name_tok.value);
            }
            declare_var(name_tok.value);
        } else {
            fprintf(out, "%s = ", name_tok.value);
        }

        if (val_peek.type == TOKEN_INPUT) {
            next_token();
            fprintf(out, "0; printf(\"> \"); scanf(\"%%d\", &%s);\n", name_tok.value);
        } else if (val_peek.type == TOKEN_LBRACKET) {
            next_token();
            fprintf(out, "{");
            while (peek_token().type != TOKEN_RBRACKET) {
                fprintf(out, "%s", next_token().value);
            }
            next_token();
            fprintf(out, "};\n");
        } else {
            compile_expression(out);
            fprintf(out, ";\n");
        }
    } else if (tok.type == TOKEN_IDENT) {
        Token op = next_token();
        fprintf(out, "%s %s ", tok.value, op.value);
        compile_expression(out);
        fprintf(out, ";\n");
    } else if (tok.type == TOKEN_IF) {
        fprintf(out, "if (");
        compile_condition(out);
        fprintf(out, ") {\n");
        next_token();
        compile_block(out);
        while (peek_token().type == TOKEN_ELIF) {
            next_token();
            fprintf(out, "else if (");
            compile_condition(out);
            fprintf(out, ") {\n");
            next_token();
            compile_block(out);
        }
        if (peek_token().type == TOKEN_ELSE) {
            next_token(); 
            fprintf(out, "else {\n");
            next_token();
            compile_block(out);
        }
    } else if (tok.type == TOKEN_WHILE) {
        fprintf(out, "while (");
        compile_condition(out);
        fprintf(out, ") {\n");
        next_token();
        compile_block(out);
    } else if (tok.type == TOKEN_FOR) {
        fprintf(out, "for (");
        next_token();
        int depth = 0;
        while (currentTokenIndex < tokenCount) {
            Token t = peek_token();
            if (t.type == TOKEN_LPAREN) depth++;
            else if (t.type == TOKEN_RPAREN) {
                if (depth == 0) { next_token(); break; }
                depth--;
            } else if (t.type == TOKEN_COMMA) {
                next_token();
                fprintf(out, "; ");
                continue;
            } else if (t.type == TOKEN_LET) {
                next_token();
                Token name_tok = next_token();
                next_token();
                fprintf(out, "int %s = ", name_tok.value);
                declare_var(name_tok.value);
                continue;
            }
            fprintf(out, "%s ", next_token().value);
        }
        fprintf(out, ") {\n");
        next_token();
        compile_block(out);
    } else if (tok.type == TOKEN_BREAK) {
        fprintf(out, "break;\n");
    } else if (tok.type == TOKEN_CONTINUE) {
        fprintf(out, "continue;\n");
    } else if (tok.type == TOKEN_SWITCH) {
        fprintf(out, "switch (");
        compile_condition(out);
        fprintf(out, ") {\n");
        next_token();
        while (currentTokenIndex < tokenCount) {
            Token t = peek_token();
            if (t.type == TOKEN_RBRACE) { next_token(); fprintf(out, "}\n"); break; }
            if (t.type == TOKEN_CASE) {
                next_token();
                fprintf(out, "case ");
                compile_expression(out);
                fprintf(out, ": {\n");
                next_token();
                compile_block(out);
                fprintf(out, "break;\n");
            } else if (t.type == TOKEN_DEFAULT) {
                next_token();
                fprintf(out, "default: {\n");
                next_token();
                compile_block(out);
            } else {
                next_token();
            }
        }
    }
}

void compile_block(FILE* out) {
    while (currentTokenIndex < tokenCount) {
        Token t = peek_token();
        if (t.type == TOKEN_RBRACE) {
            next_token();
            fprintf(out, "}\n");
            break;
        }
        if (t.type == TOKEN_EOF) break;
        compile_statement(out);
    }
}

int main(int argc, char** argv) {
    if (argc == 2 && (strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "-v") == 0)) {
        printf("Gage Programming Language v3.1.0\n"); return 0;
    }
    if (argc < 2) { printf("Usage: gage <filename.gg>\n"); return 1; }
    char* ext = strrchr(argv[1], '.');
    if (!ext || strcmp(ext, ".gg") != 0) { printf("Error: Gage can only execute files with the .gg extension!\n"); return 1; }
    
    FILE* file = fopen(argv[1], "r");
    if (!file) { printf("Error: Could not open file %s\n", argv[1]); return 1; }
    fseek(file, 0, SEEK_END); src_len = ftell(file); fseek(file, 0, SEEK_SET);
    src = malloc(src_len + 1); size_t read_bytes = fread(src, 1, src_len, file);
    src[read_bytes] = '\0'; fclose(file); 
    
    tokenize();
    
    out_funcs = fopen(".gage_funcs.c", "w");
    out_main = fopen(".gage_main.c", "w");
    
    while (currentTokenIndex < tokenCount && tokens[currentTokenIndex].type != TOKEN_EOF) {
        compile_statement(out_main);
    }
    
    fclose(out_funcs);
    fclose(out_main);
    
    FILE* out_c = fopen(".gage_temp.c", "w");
    fprintf(out_c, "#include <stdio.h>\n#include <stdlib.h>\n");
    
    FILE* f_in = fopen(".gage_funcs.c", "r");
    int c; while ((c = fgetc(f_in)) != EOF) fputc(c, out_c);
    fclose(f_in);
    
    fprintf(out_c, "int main() {\n");
    FILE* m_in = fopen(".gage_main.c", "r");
    while ((c = fgetc(m_in)) != EOF) fputc(c, out_c);
    fclose(m_in);
    
    fprintf(out_c, "return 0;\n}\n");
    fclose(out_c);
    free(src);

    printf("[Gage] Compiling script...\n");
    int status = system("clang .gage_temp.c -o .gage_executable -O3 2>/dev/null");
    
    if (status == 0) {
        system("./.gage_executable");
    } else {
        printf("[Gage] Error: Compilation failed.\n");
    }
    
    system("rm -f .gage_funcs.c .gage_main.c");
    
    return 0;
}
