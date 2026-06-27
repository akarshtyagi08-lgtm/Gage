#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

void compile_statement(FILE* out);
void compile_expression(FILE* out);
void compile_block(FILE* out);

typedef enum {
    TOKEN_CONST, TOKEN_POW, TOKEN_MOD_ASSIGN, TOKEN_EOF, TOKEN_PRINT, TOKEN_LET, 
    TOKEN_IDENT, TOKEN_INT, TOKEN_FLOAT, TOKEN_STRING, TOKEN_TRUE, TOKEN_FALSE,
    TOKEN_PLUS, TOKEN_MINUS, TOKEN_STAR, TOKEN_SLASH, TOKEN_MOD, TOKEN_PLUS_ASSIGN, 
    TOKEN_MINUS_ASSIGN, TOKEN_STAR_ASSIGN, TOKEN_SLASH_ASSIGN, TOKEN_ASSIGN, TOKEN_AND, 
    TOKEN_OR, TOKEN_NOT, TOKEN_IF, TOKEN_ELSE, TOKEN_WHILE, TOKEN_LPAREN, TOKEN_RPAREN,
    TOKEN_LBRACE, TOKEN_RBRACE, TOKEN_GT, TOKEN_LT, TOKEN_EQ, TOKEN_NEQ, TOKEN_INPUT,
    TOKEN_LBRACKET, TOKEN_RBRACKET, TOKEN_COMMA, TOKEN_ELIF, TOKEN_FOR, TOKEN_BREAK, 
    TOKEN_CONTINUE, TOKEN_SWITCH, TOKEN_CASE, TOKEN_DEFAULT, TOKEN_FN, TOKEN_RETURN,
    TOKEN_EXEC, TOKEN_SLEEP, TOKEN_CLEAR, 
    TOKEN_RENDER, TOKEN_CURSOR, TOKEN_COLOR, TOKEN_DELAY, TOKEN_HIDE_CURSOR, TOKEN_SHOW_CURSOR
} TokenType;

typedef struct { TokenType type; char value[256]; } Token;

char *src; int src_pos = 0, src_len = 0;
Token tokens[10000]; int tokenCount = 0, currentTokenIndex = 0;
char declared_vars[1000][50]; int declared_count = 0;
FILE *out_main;

int is_declared(const char* name) {
    for (int i = 0; i < declared_count; i++) if (strcmp(declared_vars[i], name) == 0) return 1;
    return 0;
}
void declare_var(const char* name) { strcpy(declared_vars[declared_count++], name); }

void tokenize() {
    while (src_pos < src_len) {
        char c = src[src_pos];
        if (isspace(c)) { src_pos++; continue; }
        
        // Comment Handling: Skip everything after ||[span_2](start_span)[span_2](end_span)
        if (c == '|' && src_pos + 1 < src_len && src[src_pos+1] == '|') {
            while (src_pos < src_len && src[src_pos] != '\n') src_pos++;
            continue;
        }

        if (c == '"') { src_pos++; int t_idx = 0; Token t; t.type = TOKEN_STRING; while (src_pos < src_len && src[src_pos] != '"') t.value[t_idx++] = src[src_pos++]; t.value[t_idx] = '\0'; tokens[tokenCount++] = t; src_pos++; continue; }
        if (isdigit(c)) { int start = src_pos; int has_dot = 0; while (src_pos < src_len && (isdigit(src[src_pos]) || src[src_pos] == '.')) { if (src[src_pos] == '.') has_dot = 1; src_pos++; } Token t; t.type = has_dot ? TOKEN_FLOAT : TOKEN_INT; int len = src_pos - start; strncpy(t.value, &src[start], len); t.value[len] = '\0'; tokens[tokenCount++] = t; continue; }
        if (isalpha(c) || c == '_') { 
            int start = src_pos; while (src_pos < src_len && (isalnum(src[src_pos]) || src[src_pos] == '_')) src_pos++; 
            Token t; int len = src_pos - start; strncpy(t.value, &src[start], len); t.value[len] = '\0'; 
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
            else t.type = TOKEN_IDENT; 
            tokens[tokenCount++] = t; continue; 
        }
        Token t; t.value[0] = c; t.value[1] = '\0';
        
        // Logical Operators[span_3](start_span)[span_3](end_span)
        if (c == '&' && src_pos + 1 < src_len && src[src_pos+1] == '&') { t.type = TOKEN_AND; strcpy(t.value, "&&"); src_pos++; }
        else if (c == '|' && src_pos + 1 < src_len && src[src_pos+1] == '|') { t.type = TOKEN_OR; strcpy(t.value, "||"); src_pos++; }
        else if (c == '+') { if (src_pos+1 < src_len && src[src_pos+1] == '=') { t.type = TOKEN_PLUS_ASSIGN; strcpy(t.value, "+="); src_pos++; } else t.type = TOKEN_PLUS; }
        else if (c == '-') { if (src_pos+1 < src_len && src[src_pos+1] == '=') { t.type = TOKEN_MINUS_ASSIGN; strcpy(t.value, "-="); src_pos++; } else t.type = TOKEN_MINUS; }
        else if (c == '%') { if (src_pos + 1 < src_len && src[src_pos + 1] == '=') { t.type = TOKEN_MOD_ASSIGN; strcpy(t.value, "%="); src_pos++; } else t.type = TOKEN_MOD; }
        else if (c == '*') { if (src_pos + 1 < src_len && src[src_pos + 1] == '*') { t.type = TOKEN_POW; strcpy(t.value, "**"); src_pos++; } else t.type = TOKEN_STAR; }
        else if (c == '=') { if (src_pos + 1 < src_len && src[src_pos + 1] == '=') { t.type = TOKEN_EQ; strcpy(t.value, "=="); src_pos++; } else t.type = TOKEN_ASSIGN; }
        else if (c == '(') t.type = TOKEN_LPAREN; else if (c == ')') t.type = TOKEN_RPAREN;
        else if (c == '{') t.type = TOKEN_LBRACE; else if (c == '}') t.type = TOKEN_RBRACE;
        else if (c == ',') t.type = TOKEN_COMMA;
        else if (c == '!') { if(src_pos+1 < src_len && src[src_pos+1] == '=') { t.type = TOKEN_NEQ; strcpy(t.value, "!="); src_pos++; } else t.type = TOKEN_NOT; }
        else if (c == '<') t.type = TOKEN_LT; else if (c == '>') t.type = TOKEN_GT; else { src_pos++; continue; }
        tokens[tokenCount++] = t; src_pos++;
    }
    Token eof; eof.type = TOKEN_EOF; strcpy(eof.value, "EOF"); tokens[tokenCount++] = eof;
}

// ... (Rest of compile_statement and main updated to v3.3.7)

int main(int argc, char** argv) {
    if (argc == 2 && (strcmp(argv[1], "--version") == 0)) { printf("Gage Programming Language v3.3.7\n"); return 0; }
    // ... (rest of main)
}
