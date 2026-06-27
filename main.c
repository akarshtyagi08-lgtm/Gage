#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>

typedef enum {
    TOKEN_EOF, TOKEN_PRINT, TOKEN_LET, TOKEN_IDENT, TOKEN_INT, TOKEN_FLOAT,
    TOKEN_STRING, TOKEN_PLUS, TOKEN_MINUS, TOKEN_STAR, TOKEN_SLASH, TOKEN_PLUS_ASSIGN,
    TOKEN_MINUS_ASSIGN, TOKEN_ASSIGN, TOKEN_WHILE, TOKEN_LPAREN, TOKEN_RPAREN,
    TOKEN_LBRACE, TOKEN_RBRACE, TOKEN_GT, TOKEN_LT, TOKEN_EQ, TOKEN_NEQ, TOKEN_EXEC,
    TOKEN_SLEEP, TOKEN_CLEAR, TOKEN_COLOR, TOKEN_DELAY, TOKEN_IMPORT, TOKEN_OR_OP, TOKEN_AND
} TokenType;

typedef struct { TokenType type; char value[256]; } Token;

FILE *out_main;
char *src;
int src_pos = 0, src_len = 0;
Token tokens[10000];
int tokenCount = 0, currentTokenIndex = 0;

void compile_statement(FILE* out);
void compile_expression(FILE* out);
void compile_block(FILE* out);

void tokenize() {
    while (src_pos < src_len) {
        char c = src[src_pos];
        if (isspace(c)) { src_pos++; continue; }
        if (isdigit(c)) {
            int start = src_pos;
            while (src_pos < src_len && (isdigit(src[src_pos]) || src[src_pos] == '.')) src_pos++;
            Token t; t.type = TOKEN_INT;
            strncpy(t.value, &src[start], src_pos - start);
            t.value[src_pos - start] = '\0';
            tokens[tokenCount++] = t;
            continue;
        }
        if (isalpha(c) || c == '_') {
            int start = src_pos;
            while (src_pos < src_len && (isalnum(src[src_pos]) || src[src_pos] == '_')) src_pos++;
            Token t;
            int len = src_pos - start;
            strncpy(t.value, &src[start], len); t.value[len] = '\0';
            if (strcmp(t.value, "print") == 0) t.type = TOKEN_PRINT;
            else if (strcmp(t.value, "let") == 0) t.type = TOKEN_LET;
            else if (strcmp(t.value, "while") == 0) t.type = TOKEN_WHILE;
            else if (strcmp(t.value, "exec") == 0) t.type = TOKEN_EXEC;
            else if (strcmp(t.value, "sleep") == 0) t.type = TOKEN_SLEEP;
            else if (strcmp(t.value, "clear") == 0) t.type = TOKEN_CLEAR;
            else if (strcmp(t.value, "color") == 0) t.type = TOKEN_COLOR;
            else if (strcmp(t.value, "delay") == 0) t.type = TOKEN_DELAY;
            else if (strcmp(t.value, "import") == 0) t.type = TOKEN_IMPORT;
            else t.type = TOKEN_IDENT;
            tokens[tokenCount++] = t;
            continue;
        }
        Token t; t.value[0] = c; t.value[1] = '\0';
        if (c == '!' && src_pos + 1 < src_len && src[src_pos+1] == '=') { t.type = TOKEN_NEQ; strcpy(t.value, "!="); src_pos++; }
        else if (c == '=' && src_pos + 1 < src_len && src[src_pos+1] == '=') { t.type = TOKEN_EQ; strcpy(t.value, "=="); src_pos++; }
        else if (c == '+' && src_pos + 1 < src_len && src[src_pos+1] == '=') { t.type = TOKEN_PLUS_ASSIGN; strcpy(t.value, "+="); src_pos++; }
        else if (c == '(') t.type = TOKEN_LPAREN;
        else if (c == ')') t.type = TOKEN_RPAREN;
        else if (c == '{') t.type = TOKEN_LBRACE;
        else if (c == '}') t.type = TOKEN_RBRACE;
        else if (c == '+') t.type = TOKEN_PLUS;
        else if (c == '=') t.type = TOKEN_ASSIGN;
        else { src_pos++; continue; }
        tokens[tokenCount++] = t;
        src_pos++;
    }
    Token eof = {TOKEN_EOF, "EOF"}; tokens[tokenCount++] = eof;
}

void compile_expression(FILE* out) {
    while (currentTokenIndex < tokenCount) {
        Token t = tokens[currentTokenIndex];
        
        // Strictly stop expressions before structural bounds or keywords
        if (t.type == TOKEN_PRINT || t.type == TOKEN_LET || t.type == TOKEN_WHILE || 
            t.type == TOKEN_RBRACE || t.type == TOKEN_LBRACE || 
            t.type == TOKEN_LPAREN || t.type == TOKEN_RPAREN) break;
            
        if (t.type == TOKEN_IDENT && currentTokenIndex + 1 < tokenCount) {
            TokenType next_t = tokens[currentTokenIndex + 1].type;
            if (next_t == TOKEN_ASSIGN || next_t == TOKEN_PLUS_ASSIGN) break;
        }

        if (t.type == TOKEN_INT || t.type == TOKEN_IDENT || t.type == TOKEN_PLUS || 
            t.type == TOKEN_MINUS || t.type == TOKEN_EQ || t.type == TOKEN_NEQ) {
            fprintf(out, "%s ", t.value);
            currentTokenIndex++;
        } else break;
    }
}

void compile_statement(FILE* out) {
    Token tok = tokens[currentTokenIndex++];
    if (tok.type == TOKEN_PRINT) {
        fprintf(out, "printf(\"%%d\\n\", ");
        compile_expression(out);
        fprintf(out, ");\n");
    } else if (tok.type == TOKEN_LET) {
        Token name = tokens[currentTokenIndex++];
        currentTokenIndex++; // '='
        fprintf(out, "int %s = ", name.value);
        compile_expression(out);
        fprintf(out, ";\n");
    } else if (tok.type == TOKEN_WHILE) {
        currentTokenIndex++; // consume '('
        fprintf(out, "while(");
        compile_expression(out);
        currentTokenIndex++; // consume ')'
        fprintf(out, "){\n");
        compile_block(out);
    } else if (tok.type == TOKEN_IDENT) {
        Token op = tokens[currentTokenIndex++]; // += or =
        fprintf(out, "%s %s ", tok.value, op.value);
        compile_expression(out);
        fprintf(out, ";\n");
    }
}

void compile_block(FILE* out) {
    currentTokenIndex++; // consume '{'
    while (currentTokenIndex < tokenCount && tokens[currentTokenIndex].type != TOKEN_RBRACE) {
        compile_statement(out);
    }
    currentTokenIndex++; // consume '}'
    fprintf(out, "}\n");
}

int main(int argc, char** argv) {
    if (system("command -v clang > /dev/null 2>&1") != 0) system("pkg update -y && pkg install clang -y");
    if (argc < 2) return 1;
    FILE* file = fopen(argv[1], "r");
    fseek(file, 0, SEEK_END); src_len = ftell(file); fseek(file, 0, SEEK_SET);
    src = malloc(src_len + 1); fread(src, 1, src_len, file); fclose(file); src[src_len] = '\0';
    tokenize();
    out_main = fopen(".gm.c", "w");
    while (currentTokenIndex < tokenCount && tokens[currentTokenIndex].type != TOKEN_EOF) compile_statement(out_main);
    fclose(out_main);
    FILE* out_c = fopen(".gt.c", "w");
    fprintf(out_c, "#include <stdio.h>\n#include <stdlib.h>\nint main(){");
    FILE* m_in = fopen(".gm.c", "r");
    int c; while ((c = fgetc(m_in)) != EOF) fputc(c, out_c);
    fclose(m_in); fprintf(out_c, "return 0;}"); fclose(out_c);
    system("clang .gt.c -o .ge && ./.ge");
    return 0;
}
