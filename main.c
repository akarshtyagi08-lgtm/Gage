#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>

FILE *out_main;
char *src; int src_pos = 0, src_len = 0;
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
Token tokens[10000]; int tokenCount = 0, currentTokenIndex = 0;
char declared_vars[1000][50]; int declared_count = 0;

int is_declared(const char* name) { for (int i = 0; i < declared_count; i++) if (strcmp(declared_vars[i], name) == 0) return 1; return 0; }
void declare_var(const char* name) { strcpy(declared_vars[declared_count++], name); }
void throw_lint_error(const char* msg, const char* var_name) { printf("\033[1;31m[Gage Linter Error]\033[0m %s '%s'\n", msg, var_name); exit(1); }

void tokenize() {
    while (src_pos < src_len) {
        char c = src[src_pos];
        if (isspace(c)) { src_pos++; continue; }
        if (c == '|' && src_pos + 1 < src_len && src[src_pos+1] == '|') {
            src_pos += 2;
            while (src_pos < src_len && !(src[src_pos] == '|' && src[src_pos+1] == '|')) src_pos++;
            src_pos += 2; continue;
        }
        if (c == '"') { src_pos++; int t_idx = 0; Token t; t.type = TOKEN_STRING; while (src_pos < src_len && src[src_pos] != '"') t.value[t_idx++] = src[src_pos++]; t.value[t_idx] = '\0'; tokens[tokenCount++] = t; src_pos++; continue; }
        if (isdigit(c)) { int start = src_pos; int has_dot = 0; while (src_pos < src_len && (isdigit(src[src_pos]) || src[src_pos] == '.')) { if (src[src_pos] == '.') has_dot = 1; src_pos++; } Token t; t.type = has_dot ? TOKEN_FLOAT : TOKEN_INT; int len = src_pos - start; strncpy(t.value, &src[start], len); t.value[len] = '\0'; tokens[tokenCount++] = t; continue; }
        if (isalpha(c) || c == '_') { 
            int start = src_pos; while (src_pos < src_len && (isalnum(src[src_pos]) || src[src_pos] == '_')) src_pos++; 
            Token t; int len = src_pos - start; strncpy(t.value, &src[start], len); t.value[len] = '\0'; 
            if (strcmp(t.value, "print") == 0) t.type = TOKEN_PRINT; else if (strcmp(t.value, "let") == 0) t.type = TOKEN_LET; else if (strcmp(t.value, "const") == 0) t.type = TOKEN_CONST; else if (strcmp(t.value, "while") == 0) t.type = TOKEN_WHILE; else if (strcmp(t.value, "exec") == 0) t.type = TOKEN_EXEC; else if (strcmp(t.value, "sleep") == 0) t.type = TOKEN_SLEEP; else if (strcmp(t.value, "clear") == 0) t.type = TOKEN_CLEAR; else if (strcmp(t.value, "render") == 0) t.type = TOKEN_RENDER; else if (strcmp(t.value, "cursor") == 0) t.type = TOKEN_CURSOR; else if (strcmp(t.value, "color") == 0) t.type = TOKEN_COLOR; else if (strcmp(t.value, "delay") == 0) t.type = TOKEN_DELAY; else if (strcmp(t.value, "hide_cursor") == 0) t.type = TOKEN_HIDE_CURSOR; else if (strcmp(t.value, "show_cursor") == 0) t.type = TOKEN_SHOW_CURSOR; else if (strcmp(t.value, "import") == 0) t.type = TOKEN_IMPORT; else if (strcmp(t.value, "OR") == 0) t.type = TOKEN_OR_OP; else t.type = TOKEN_IDENT; 
            tokens[tokenCount++] = t; continue; 
        }
        Token t; t.value[0] = c; t.value[1] = '\0';
        if (c == '&' && src_pos + 1 < src_len && src[src_pos+1] == '&') { t.type = TOKEN_AND; strcpy(t.value, "&&"); src_pos++; }
        else if (c == '+') { if (src_pos+1 < src_len && src[src_pos+1] == '=') { t.type = TOKEN_PLUS_ASSIGN; strcpy(t.value, "+="); src_pos++; } else t.type = TOKEN_PLUS; }
        else if (c == '=') { if (src_pos + 1 < src_len && src[src_pos + 1] == '=') { t.type = TOKEN_EQ; strcpy(t.value, "=="); src_pos++; } else t.type = TOKEN_ASSIGN; }
        else if (c == '(') t.type = TOKEN_LPAREN; else if (c == ')') t.type = TOKEN_RPAREN;
        else if (c == '{') t.type = TOKEN_LBRACE; else if (c == '}') t.type = TOKEN_RBRACE;
        else if (c == ',') t.type = TOKEN_COMMA;
        else if (c == '<') t.type = TOKEN_LT; else if (c == '>') t.type = TOKEN_GT; else { src_pos++; continue; }
        tokens[tokenCount++] = t; src_pos++;
    }
    Token eof; eof.type = TOKEN_EOF; strcpy(eof.value, "EOF"); tokens[tokenCount++] = eof;
}

Token peek_token() { return (currentTokenIndex >= tokenCount) ? tokens[tokenCount - 1] : tokens[currentTokenIndex]; }
Token next_token() { Token t = peek_token(); if (currentTokenIndex < tokenCount) currentTokenIndex++; return t; }

int is_std_func(const char* name) { const char* std_funcs[] = {"abs", "sqrt", "max", "min", "sin", "cos", "tan", "log", "ceil", "floor", "round", "randint", "rand_float", "timestamp", "clock_ticks", "str_len"}; for(int i=0; i<16; i++) if (strcmp(name, std_funcs[i]) == 0) return 1; return 0; }

void compile_expression(FILE* out) {
    int expect_operator = 0; int paren_depth = 0;
    while (currentTokenIndex < tokenCount) {
        Token t = peek_token();
        int is_operand = (t.type == TOKEN_INT || t.type == TOKEN_FLOAT || t.type == TOKEN_IDENT);
        if (expect_operator && is_operand) break; 
        if (t.type == TOKEN_INT || t.type == TOKEN_FLOAT || t.type == TOKEN_PLUS || t.type == TOKEN_MINUS || t.type == TOKEN_STAR || t.type == TOKEN_SLASH || t.type == TOKEN_MOD || t.type == TOKEN_EQ || t.type == TOKEN_NEQ || t.type == TOKEN_LT || t.type == TOKEN_GT || t.type == TOKEN_LPAREN || t.type == TOKEN_RPAREN || t.type == TOKEN_COMMA || t.type == TOKEN_AND || t.type == TOKEN_OR_OP) {
            if (t.type == TOKEN_LPAREN) paren_depth++;
            if (t.type == TOKEN_RPAREN) { if (paren_depth == 0) break; paren_depth--; }
            fprintf(out, "%s ", next_token().value);
            if (t.type == TOKEN_LPAREN || t.type == TOKEN_COMMA) { expect_operator = 0; } else if (t.type == TOKEN_RPAREN) { expect_operator = 1; } else { expect_operator = is_operand; }
        } else if (t.type == TOKEN_IDENT) {
            if (currentTokenIndex + 1 < tokenCount) { TokenType nt = tokens[currentTokenIndex + 1].type; if (nt == TOKEN_ASSIGN || nt == TOKEN_MOD_ASSIGN || nt == TOKEN_PLUS_ASSIGN || nt == TOKEN_MINUS_ASSIGN) break; }
            if (!is_std_func(t.value) && !is_declared(t.value)) { throw_lint_error("Undeclared variable/function used:", t.value); }
            if (strcmp(t.value, "abs") == 0) fprintf(out, "fabs "); else fprintf(out, "%s ", t.value);
            next_token(); expect_operator = 1;
        } else { break; }
    }
}

void compile_condition(FILE* out) {
    if (peek_token().type == TOKEN_LPAREN) next_token();
    int paren_depth = 0;
    while (currentTokenIndex < tokenCount) {
        Token t = peek_token();
        if (t.type == TOKEN_LPAREN) paren_depth++;
        if (t.type == TOKEN_RPAREN) { if (paren_depth == 0) { next_token(); break; } paren_depth--; }
        if (t.type == TOKEN_EOF) break;
        fprintf(out, "%s ", next_token().value);
    }
}

void compile_block(FILE* out) { next_token(); while (currentTokenIndex < tokenCount) { Token t = peek_token(); if (t.type == TOKEN_RBRACE) { next_token(); fprintf(out, "}\n"); break; } if (t.type == TOKEN_EOF) break; compile_statement(out); } }

void compile_statement(FILE* out) {
    Token tok = next_token();
    if (tok.type == TOKEN_IMPORT) { Token mod = next_token(); fprintf(out, "// GAGE IMPORTED MODULE: %s\n", mod.value); if (strcmp(mod.value, "random") == 0) fprintf(out, "srand(time(NULL));\n"); }
    else if (tok.type == TOKEN_PRINT || tok.type == TOKEN_RENDER) {
        int has_paren = 0; if (peek_token().type == TOKEN_LPAREN) { next_token(); has_paren = 1; }
        Token next = peek_token(); const char* end_char = (tok.type == TOKEN_PRINT) ? "\\n" : "";
        if (next.type == TOKEN_STRING) { next_token(); fprintf(out, "printf(\"%%s%s\", \"%s\");\n", end_char, next.value); } else { fprintf(out, "printf(\"%%g%s\", (double)(" , end_char); compile_expression(out); fprintf(out, "));\n"); }
        if (tok.type == TOKEN_RENDER) fprintf(out, "fflush(stdout);\n");
        if (has_paren && peek_token().type == TOKEN_RPAREN) next_token();
    } else if (tok.type == TOKEN_DELAY || tok.type == TOKEN_COLOR || tok.type == TOKEN_CURSOR || tok.type == TOKEN_HIDE_CURSOR || tok.type == TOKEN_SHOW_CURSOR) {
        int has_paren = 0; if (peek_token().type == TOKEN_LPAREN) { next_token(); has_paren = 1; }
        fprintf(out, "%s(", tok.value); if (tok.type != TOKEN_HIDE_CURSOR && tok.type != TOKEN_SHOW_CURSOR) compile_expression(out); fprintf(out, ");\n");
        if (has_paren && peek_token().type == TOKEN_RPAREN) next_token();
    } else if (tok.type == TOKEN_CLEAR) { fprintf(out, "system(\"clear\");\n"); if (peek_token().type == TOKEN_LPAREN) { next_token(); if (peek_token().type == TOKEN_RPAREN) next_token(); } }
    else if (tok.type == TOKEN_SLEEP) { int has_paren = 0; if (peek_token().type == TOKEN_LPAREN) { next_token(); has_paren = 1; } fprintf(out, "sleep((unsigned int)("); compile_expression(out); fprintf(out, "));\n"); if (has_paren && peek_token().type == TOKEN_RPAREN) next_token(); }
    else if (tok.type == TOKEN_EXEC) { int has_paren = 0; if (peek_token().type == TOKEN_LPAREN) { next_token(); has_paren = 1; } Token next = peek_token(); if (next.type == TOKEN_STRING) { next_token(); fprintf(out, "system(\"%s\");\n", next.value); } if (has_paren && peek_token().type == TOKEN_RPAREN) next_token(); }
    else if (tok.type == TOKEN_LET || tok.type == TOKEN_CONST) { Token name = next_token(); next_token(); fprintf(out, "%s %s = ", (tok.type == TOKEN_CONST ? "const double" : "int"), name.value); compile_expression(out); fprintf(out, ";\n"); declare_var(name.value); }
    else if (tok.type == TOKEN_IDENT) { Token op = next_token(); if (op.type == TOKEN_ASSIGN || op.type == TOKEN_PLUS_ASSIGN || op.type == TOKEN_MINUS_ASSIGN) { if (!is_declared(tok.value)) { throw_lint_error("Undeclared variable:", tok.value); } fprintf(out, "%s %s ", tok.value, op.value); compile_expression(out); fprintf(out, ";\n"); } }
    else if (tok.type == TOKEN_WHILE) { fprintf(out, "while ("); compile_condition(out); fprintf(out, ") {\n"); compile_block(out); }
}

int main(int argc, char** argv) {
    if (argc < 2) { printf("Usage: gage <filename.gg>\n"); return 1; }
    FILE* file = fopen(argv[1], "r"); if (!file) { printf("Error: Could not open file.\n"); return 1; }
    fseek(file, 0, SEEK_END); src_len = ftell(file); fseek(file, 0, SEEK_SET); src = malloc(src_len + 1); fread(src, 1, src_len, file); fclose(file); src[src_len] = '\0';
    tokenize(); char* tmp = getenv("TMPDIR") ? getenv("TMPDIR") : "/tmp"; char p_m[512], p_t[512], p_e[512]; sprintf(p_m, "%s/.gm.c", tmp); sprintf(p_t, "%s/.gt.c", tmp); sprintf(p_e, "%s/.ge", tmp);
    out_main = fopen(p_m, "w"); while (currentTokenIndex < tokenCount && tokens[currentTokenIndex].type != TOKEN_EOF) compile_statement(out_main); fclose(out_main);
    FILE* out_c = fopen(p_t, "w");
    fprintf(out_c, "#include <stdio.h>\n#include <stdlib.h>\n#include <math.h>\n#include <unistd.h>\n#include <time.h>\n#include <string.h>\n#include <ctype.h>\n#define max(a,b) ((a)>(b)?(a):(b))\n#define min(a,b) ((a)<(b)?(a):(b))\n#define delay(ms) usleep((unsigned int)(ms)*1000)\n#define color(c) printf(\"\\033[%%dm\", (int)(c))\n#define cursor(x,y) printf(\"\\033[%%d;%%dH\", (int)(y), (int)(x))\n#define hide_cursor() printf(\"\\033[?25l\")\n#define show_cursor() printf(\"\\033[?25h\")\n#define randint(min, max) (rand() %% ((max) - (min) + 1) + (min))\n#define rand_float() ((double)rand() / (double)RAND_MAX)\n#define timestamp() (long)time(NULL)\n#define str_len(s) strlen(s)\nint main(){");
    FILE* m_in = fopen(p_m, "r"); int c; while ((c = fgetc(m_in)) != EOF) fputc(c, out_c); fclose(m_in);
    fprintf(out_c, "return 0;}"); fclose(out_c); free(src);
    char cmd[1024]; sprintf(cmd, "clang -O0 -w %s -o %s -lm && %s", p_t, p_e, p_e); system(cmd); char clean[1024]; sprintf(clean, "rm -f %s %s %s", p_m, p_t, p_e); system(clean); return 0;
}
