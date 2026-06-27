#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>

// --- TOKEN DEFINITIONS ---
typedef enum {
    TOKEN_CONST, TOKEN_POW, TOKEN_MOD_ASSIGN, TOKEN_EOF, TOKEN_PRINT, TOKEN_LET,
    TOKEN_IDENT, TOKEN_INT, TOKEN_FLOAT, TOKEN_STRING, TOKEN_TRUE, TOKEN_FALSE,
    TOKEN_PLUS, TOKEN_MINUS, TOKEN_STAR, TOKEN_SLASH, TOKEN_MOD, TOKEN_PLUS_ASSIGN,
    TOKEN_MINUS_ASSIGN, TOKEN_STAR_ASSIGN, TOKEN_SLASH_ASSIGN, TOKEN_ASSIGN, TOKEN_AND,
    TOKEN_OR, TOKEN_NOT, TOKEN_IF, TOKEN_ELSE, TOKEN_WHILE, TOKEN_LPAREN, TOKEN_RPAREN,
    TOKEN_LBRACE, TOKEN_RBRACE, TOKEN_GT, TOKEN_LT, TOKEN_EQ, TOKEN_NEQ, TOKEN_INPUT,
    TOKEN_LBRACKET, TOKEN_RBRACKET, TOKEN_COMMA, TOKEN_ELIF, TOKEN_FOR, TOKEN_BREAK,
    TOKEN_CONTINUE, TOKEN_SWITCH, TOKEN_CASE, TOKEN_DEFAULT, TOKEN_FN, TOKEN_RETURN,
    TOKEN_EXEC, TOKEN_SLEEP, TOKEN_CLEAR, TOKEN_RENDER, TOKEN_CURSOR, TOKEN_COLOR,
    TOKEN_DELAY, TOKEN_HIDE_CURSOR, TOKEN_SHOW_CURSOR, TOKEN_IMPORT, TOKEN_OR_OP
} TokenType;

typedef struct { TokenType type; char value[256]; } Token;

// --- GLOBAL VARIABLES ---
FILE *out_main;
char *src;
int src_pos = 0, src_len = 0;
Token tokens[10000];
int tokenCount = 0, currentTokenIndex = 0;
char declared_vars[1000][50];
int declared_count = 0;

// --- PROTOTYPES ---
void compile_statement(FILE* out);
void compile_expression(FILE* out);
void compile_block(FILE* out);
void tokenize();
int is_declared(const char* name);
void declare_var(const char* name);
void throw_lint_error(const char* msg, const char* var_name);

// --- LOGIC IMPLEMENTATIONS ---
int is_declared(const char* name) {
    for (int i = 0; i < declared_count; i++)
        if (strcmp(declared_vars[i], name) == 0) return 1;
    return 0;
}
void declare_var(const char* name) {
    strcpy(declared_vars[declared_count++], name);
}
void throw_lint_error(const char* msg, const char* var_name) {
    printf("\033[1;31m[Gage Linter Error]\033[0m %s '%s'\n", msg, var_name);
    exit(1);
}

void tokenize() {
    while (src_pos < src_len) {
        char c = src[src_pos];
        if (isspace(c)) { src_pos++; continue; }
        if (c == '|' && src_pos + 1 < src_len && src[src_pos+1] == '|') {
            src_pos += 2;
            while (src_pos < src_len && !(src[src_pos] == '|' && src[src_pos+1] == '|'))
                src_pos++;
            src_pos += 2;
            continue;
        }
        if (c == '"') {
            src_pos++;
            int t_idx = 0;
            Token t;
            t.type = TOKEN_STRING;
            while (src_pos < src_len && src[src_pos] != '"')
                t.value[t_idx++] = src[src_pos++];
            t.value[t_idx] = '\0';
            tokens[tokenCount++] = t;
            src_pos++;
            continue;
        }
        if (isdigit(c)) {
            int start = src_pos;
            int has_dot = 0;
            while (src_pos < src_len && (isdigit(src[src_pos]) || src[src_pos] == '.')) {
                if (src[src_pos] == '.') has_dot = 1;
                src_pos++;
            }
            Token t;
            t.type = has_dot ? TOKEN_FLOAT : TOKEN_INT;
            int len = src_pos - start;
            strncpy(t.value, &src[start], len);
            t.value[len] = '\0';
            tokens[tokenCount++] = t;
            continue;
        }
        if (isalpha(c) || c == '_') {
            int start = src_pos;
            while (src_pos < src_len && (isalnum(src[src_pos]) || src[src_pos] == '_'))
                src_pos++;
            Token t;
            int len = src_pos - start;
            strncpy(t.value, &src[start], len);
            t.value[len] = '\0';
            if (strcmp(t.value, "print") == 0) t.type = TOKEN_PRINT;
            else if (strcmp(t.value, "let") == 0) t.type = TOKEN_LET;
            else if (strcmp(t.value, "const") == 0) t.type = TOKEN_CONST;
            else if (strcmp(t.value, "while") == 0) t.type = TOKEN_WHILE;
            else if (strcmp(t.value, "exec") == 0) t.type = TOKEN_EXEC;
            else if (strcmp(t.value, "sleep") == 0) t.type = TOKEN_SLEEP;
            else if (strcmp(t.value, "clear") == 0) t.type = TOKEN_CLEAR;
            else if (strcmp(t.value, "render") == 0) t.type = TOKEN_RENDER;
            else if (strcmp(t.value, "cursor") == 0) t.type = TOKEN_CURSOR;
            else if (strcmp(t.value, "color") == 0) t.type = TOKEN_COLOR;
            else if (strcmp(t.value, "delay") == 0) t.type = TOKEN_DELAY;
            else if (strcmp(t.value, "hide_cursor") == 0) t.type = TOKEN_HIDE_CURSOR;
            else if (strcmp(t.value, "show_cursor") == 0) t.type = TOKEN_SHOW_CURSOR;
            else if (strcmp(t.value, "import") == 0) t.type = TOKEN_IMPORT;
            else if (strcmp(t.value, "OR") == 0) t.type = TOKEN_OR_OP;
            else t.type = TOKEN_IDENT;
            tokens[tokenCount++] = t;
            continue;
        }
        Token t;
        t.value[0] = c;
        t.value[1] = '\0';
        if (c == '&' && src_pos + 1 < src_len && src[src_pos+1] == '&') {
            t.type = TOKEN_AND;
            strcpy(t.value, "&&");
            src_pos++;
        } else if (c == '+') {
            if (src_pos+1 < src_len && src[src_pos+1] == '=') {
                t.type = TOKEN_PLUS_ASSIGN;
                strcpy(t.value, "+=");
                src_pos++;
            } else t.type = TOKEN_PLUS;
        } else if (c == '=') {
            if (src_pos + 1 < src_len && src[src_pos + 1] == '=') {
                t.type = TOKEN_EQ;
                strcpy(t.value, "==");
                src_pos++;
            } else t.type = TOKEN_ASSIGN;
        } else if (c == '(') t.type = TOKEN_LPAREN;
        else if (c == ')') t.type = TOKEN_RPAREN;
        else if (c == '{') t.type = TOKEN_LBRACE;
        else if (c == '}') t.type = TOKEN_RBRACE;
        else if (c == ',') t.type = TOKEN_COMMA;
        else if (c == '<') t.type = TOKEN_LT;
        else if (c == '>') t.type = TOKEN_GT;
        else { src_pos++; continue; }
        tokens[tokenCount++] = t;
        src_pos++;
    }
    Token eof;
    eof.type = TOKEN_EOF;
    strcpy(eof.value, "EOF");
    tokens[tokenCount++] = eof;
}

Token peek_token() {
    return (currentTokenIndex >= tokenCount) ? tokens[tokenCount - 1] : tokens[currentTokenIndex];
}
Token next_token() {
    Token t = peek_token();
    if (currentTokenIndex < tokenCount) currentTokenIndex++;
    return t;
}

void compile_expression(FILE* out) {
    while (currentTokenIndex < tokenCount) {
        Token t = peek_token();
        if (t.type == TOKEN_INT || t.type == TOKEN_FLOAT || t.type == TOKEN_IDENT ||
            t.type == TOKEN_PLUS || t.type == TOKEN_MINUS || t.type == TOKEN_AND ||
            t.type == TOKEN_OR_OP) {
            fprintf(out, "%s ", next_token().value);
        } else break;
    }
}

void compile_block(FILE* out) {
    next_token(); // consume '{'
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

void compile_statement(FILE* out) {
    Token tok = next_token();
    if (tok.type == TOKEN_PRINT) {
        fprintf(out, "printf(\"%%d\\n\", ");
        compile_expression(out);
        fprintf(out, ");\n");
    } else if (tok.type == TOKEN_LET) {
        Token name = next_token();
        next_token(); // consume '='
        fprintf(out, "int %s = ", name.value);
        compile_expression(out);
        fprintf(out, ";\n");
        declare_var(name.value);
    } else if (tok.type == TOKEN_WHILE) {
        fprintf(out, "while(");
        compile_expression(out);
        fprintf(out, "){\n");
        compile_block(out);
    } else if (tok.type == TOKEN_EXEC) {
        Token cmd = next_token(); // string token
        fprintf(out, "system(\"%s\");\n", cmd.value);
    } else if (tok.type == TOKEN_SLEEP) {
        Token time = next_token(); // number token
        fprintf(out, "sleep(%s);\n", time.value);
    } else if (tok.type == TOKEN_CLEAR) {
        fprintf(out, "system(\"clear\");\n");
    } else if (tok.type == TOKEN_COLOR) {
        fprintf(out, "printf(\"\\033[%%dm\", ");
        compile_expression(out);
        fprintf(out, ");\n");
    } else if (tok.type == TOKEN_DELAY) {
        fprintf(out, "usleep(");
        compile_expression(out);
        fprintf(out, "*1000);\n");
    } else if (tok.type == TOKEN_IMPORT) {
        Token mod = next_token();
        fprintf(out, "// Module: %s\n", mod.value);
        if (strcmp(mod.value, "random") == 0)
            fprintf(out, "srand(time(NULL));\n");
    }
}

int main(int argc, char** argv) {
    if (argc == 2 && (strcmp(argv[1], "help") == 0 || strcmp(argv[1], "--help") == 0)) {
        printf("\n=== GAGE v3.4.1 HELP ===\nCommands: gage <file.gg>\nFeatures: let, print, while, exec, import, color, clear, delay.\nSee DOCS.md for details.\n\n");
        return 0;
    }
    // FIXED: Now supports -v and --version
    if (argc == 2 && (strcmp(argv[1], "version") == 0 || strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "-v") == 0)) {
        printf("Gage Compiler v3.4.1\n");
        return 0;
    }
    if (argc < 2) {
        printf("Usage: gage <filename.gg>\n");
        return 1;
    }
    FILE* file = fopen(argv[1], "r");
    if (!file) return 1;
    fseek(file, 0, SEEK_END);
    src_len = ftell(file);
    fseek(file, 0, SEEK_SET);
    src = malloc(src_len + 1);
    fread(src, 1, src_len, file);
    fclose(file);
    src[src_len] = '\0';

    tokenize();

    char p_m[] = ".gm.c", p_t[] = ".gt.c", p_e[] = ".ge";
    out_main = fopen(p_m, "w");
    while (currentTokenIndex < tokenCount && tokens[currentTokenIndex].type != TOKEN_EOF)
        compile_statement(out_main);
    fclose(out_main);

    FILE* out_c = fopen(p_t, "w");
    fprintf(out_c, "#include <stdio.h>\n#include <stdlib.h>\n#include <time.h>\n#include <unistd.h>\nint main(){");
    FILE* m_in = fopen(p_m, "r");
    int c;
    while ((c = fgetc(m_in)) != EOF) fputc(c, out_c);
    fclose(m_in);
    fprintf(out_c, "return 0;}");
    fclose(out_c);

    char cmd[1024];
    sprintf(cmd, "clang %s -o %s && %s", p_t, p_e, p_e);
    system(cmd);
    return 0;
}
