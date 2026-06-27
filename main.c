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
    for (int i = 0; i < declared_count; i++) if (strcmp(declared_vars[i], name) == 0) return 1;
    return 0;
}
void declare_var(const char* name) { strcpy(declared_vars[declared_count++], name); }

void tokenize() {
    while (src_pos < src_len) {
        char c = src[src_pos];
        if (isspace(c)) { src_pos++; continue; }
        if (c == '"') {
            src_pos++; int t_idx = 0; Token t; t.type = TOKEN_STRING;
            while (src_pos < src_len && src[src_pos] != '"') t.value[t_idx++] = src[src_pos++];
            t.value[t_idx] = '\0'; tokens[tokenCount++] = t; src_pos++; continue;
        }
        if (isdigit(c)) {
            int start = src_pos; int has_dot = 0;
            while (src_pos < src_len && (isdigit(src[src_pos]) || src[src_pos] == '.')) { if (src[src_pos] == '.') has_dot = 1; src_pos++; }
            Token t; t.type = has_dot ? TOKEN_FLOAT : TOKEN_INT;
            int len = src_pos - start; strncpy(t.value, &src[start], len); t.value[len] = '\0';
            tokens[tokenCount++] = t; continue;
        }
        if (isalpha(c) || c == '_') {
            int start = src_pos; while (src_pos < src_len && (isalnum(src[src_pos]) || src[src_pos] == '_')) src_pos++;
            Token t; int len = src_pos - start; strncpy(t.value, &src[start], len); t.value[len] = '\0';
            if (strcmp(t.value, "print") == 0) t.type = TOKEN_PRINT;
            else if (strcmp(t.value, "let") == 0) t.type = TOKEN_LET;
            else if (strcmp(t.value, "const") == 0) t.type = TOKEN_CONST;
            else t.type = TOKEN_IDENT;
            tokens[tokenCount++] = t; continue;
        }
        Token t; t.value[0] = c; t.value[1] = '\0';
        if (c == '%') { if (src_pos + 1 < src_len && src[src_pos + 1] == '=') { t.type = TOKEN_MOD_ASSIGN; strcpy(t.value, "%="); src_pos++; } else t.type = TOKEN_MOD; }
        else if (c == '*') { if (src_pos + 1 < src_len && src[src_pos + 1] == '*') { t.type = TOKEN_POW; strcpy(t.value, "**"); src_pos++; } else t.type = TOKEN_STAR; }
        else if (c == '=') t.type = TOKEN_ASSIGN;
        else { src_pos++; continue; }
        tokens[tokenCount++] = t; src_pos++;
    }
    Token eof; eof.type = TOKEN_EOF; strcpy(eof.value, "EOF"); tokens[tokenCount++] = eof;
}

Token peek_token() { return (currentTokenIndex >= tokenCount) ? tokens[tokenCount - 1] : tokens[currentTokenIndex]; }
Token next_token() { Token t = peek_token(); if (currentTokenIndex < tokenCount) currentTokenIndex++; return t; }

void compile_expression(FILE* out) {
    while (currentTokenIndex < tokenCount) {
        Token t = peek_token();
        if (t.type == TOKEN_INT || t.type == TOKEN_FLOAT) {
            fprintf(out, "%s ", next_token().value);
        } else if (t.type == TOKEN_IDENT) {
            if (currentTokenIndex + 1 < tokenCount) {
                TokenType nt = tokens[currentTokenIndex + 1].type;
                if (nt == TOKEN_ASSIGN || nt == TOKEN_MOD_ASSIGN) break;
            }
            fprintf(out, "%s ", next_token().value);
        } else break;
    }
}

void compile_statement(FILE* out) {
    Token tok = next_token();
    if (tok.type == TOKEN_PRINT) {
        int is_pow = 0;
        if (tokens[currentTokenIndex + 1].type == TOKEN_POW) is_pow = 1;

        if (is_pow) {
            fprintf(out, "printf(\"%%g\\n\", pow(");
            fprintf(out, "%s ", next_token().value);
            next_token(); 
            fprintf(out, ", %s", next_token().value);
            fprintf(out, "));\n");
        } else {
            fprintf(out, "printf(\"%%g\\n\", (double)(");
            compile_expression(out);
            fprintf(out, "));\n");
        }
    } else if (tok.type == TOKEN_LET || tok.type == TOKEN_CONST) {
        Token name = next_token(); next_token();
        fprintf(out, "%s %s = ", (tok.type == TOKEN_CONST ? "const double" : "int"), name.value);
        compile_expression(out); fprintf(out, ";\n");
        declare_var(name.value);
    } else if (tok.type == TOKEN_IDENT) {
        Token op = next_token();
        if (op.type == TOKEN_MOD_ASSIGN) {
            fprintf(out, "%s = %s %% ", tok.value, tok.value);
            compile_expression(out); fprintf(out, ";\n");
        }
    }
}

int main(int argc, char** argv) {
    if (argc < 2) { printf("Usage: gage <filename.gg>\n"); return 1; }
    FILE* file = fopen(argv[1], "r");
    if (!file) { printf("Error: Could not open file %s\n", argv[1]); return 1; }
    fseek(file, 0, SEEK_END); src_len = ftell(file); fseek(file, 0, SEEK_SET);
    src = malloc(src_len + 1); fread(src, 1, src_len, file); src[src_len] = '\0'; fclose(file); 
    
    tokenize();

    // Dynamically look for safe Termux or Linux temp directory path
    char* temp_dir = getenv("TMPDIR");
    if (!temp_dir) temp_dir = "/tmp";

    char path_funcs[512], path_main[512], path_temp[512], path_exec[512];
    sprintf(path_funcs, "%s/.gage_funcs.c", temp_dir);
    sprintf(path_main, "%s/.gage_main.c", temp_dir);
    sprintf(path_temp, "%s/.gage_temp.c", temp_dir);
    sprintf(path_exec, "%s/.gage_executable", temp_dir);

    out_funcs = fopen(path_funcs, "w"); 
    out_main = fopen(path_main, "w");
    if (!out_funcs || !out_main) { printf("Error: Could not open working directory files.\n"); return 1; }

    while (currentTokenIndex < tokenCount && tokens[currentTokenIndex].type != TOKEN_EOF) compile_statement(out_main);
    fclose(out_funcs); fclose(out_main);
    
    FILE* out_c = fopen(path_temp, "w");
    if (!out_c) { printf("Error: Could not write build template.\n"); return 1; }
    fprintf(out_c, "#include <stdio.h>\n#include <stdlib.h>\n#include <math.h>\nint main() {\n");
    FILE* m_in = fopen(path_main, "r"); int c; while ((c = fgetc(m_in)) != EOF) fputc(c, out_c);
    fclose(m_in); fprintf(out_c, "return 0;\n}\n"); fclose(out_c); free(src);

    printf("\033[1;32m   Compiling\033[0m target logic via clang...\n");
    
    char compile_cmd[1024];
    sprintf(compile_cmd, "clang %s -o %s -lm 2>/dev/null", path_temp, path_exec);
    int status = system(compile_cmd);
    
    if (status == 0) {
        char run_cmd[512];
        sprintf(run_cmd, "%s", path_exec);
        system(run_cmd);
    } else {
        printf("\033[1;31m      Error\033[0m: Target transpile parsing failed.\n");
    }

    char clean_cmd[1024];
    sprintf(clean_cmd, "rm -f %s %s %s %s", path_funcs, path_main, path_temp, path_exec);
    system(clean_cmd);
    return 0;
}
