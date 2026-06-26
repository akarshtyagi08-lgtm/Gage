#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {
    TOKEN_EOF,
    TOKEN_PRINT,
    TOKEN_LET,
    TOKEN_IDENT,
    TOKEN_INT,
    TOKEN_STRING,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_STAR,
    TOKEN_SLASH,
    TOKEN_ASSIGN,
    TOKEN_IF,
    TOKEN_ELSE,
    TOKEN_WHILE,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_LBRACE,
    TOKEN_RBRACE,
    TOKEN_GT,
    TOKEN_LT,
    TOKEN_EQ
} TokenType;

typedef struct {
    TokenType type;
    char value[256];
} Token;

typedef struct {
    char name[50];
    int value;
} Variable;

#define MAX_VARIABLES 100
Variable symbolTable[MAX_VARIABLES];
int variableCount = 0;

char *src;
int src_pos = 0;
int src_len = 0;

Token tokens[10000];
int tokenCount = 0;
int currentTokenIndex = 0;

void set_variable(const char* name, int value) {
    for (int i = 0; i < variableCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            symbolTable[i].value = value;
            return;
        }
    }
    if (variableCount < MAX_VARIABLES) {
        strcpy(symbolTable[variableCount].name, name);
        symbolTable[variableCount].value = value;
        variableCount++;
    } else {
        printf("Runtime Error: Variable limit reached\n");
        exit(1);
    }
}

int get_variable(const char* name) {
    for (int i = 0; i < variableCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            return symbolTable[i].value;
        }
    }
    printf("Runtime Error: Undefined variable '%s'\n", name);
    exit(1);
}

void tokenize() {
    while (src_pos < src_len) {
        char c = src[src_pos];

        if (isspace(c)) {
            src_pos++;
            continue;
        }

        if (c == '"') {
            int start = ++src_pos;
            while (src_pos < src_len && src[src_pos] != '"') {
                src_pos++;
            }
            Token t;
            t.type = TOKEN_STRING;
            int len = src_pos - start;
            strncpy(t.value, &src[start], len);
            t.value[len] = '\0';
            tokens[tokenCount++] = t;
            src_pos++;
            continue;
        }

        if (isdigit(c)) {
            int start = src_pos;
            while (src_pos < src_len && isdigit(src[src_pos])) {
                src_pos++;
            }
            Token t;
            t.type = TOKEN_INT;
            int len = src_pos - start;
            strncpy(t.value, &src[start], len);
            t.value[len] = '\0';
            tokens[tokenCount++] = t;
            continue;
        }

        if (isalpha(c) || c == '_') {
            int start = src_pos;
            while (src_pos < src_len && (isalnum(src[src_pos]) || src[src_pos] == '_')) {
                src_pos++;
            }
            Token t;
            int len = src_pos - start;
            strncpy(t.value, &src[start], len);
            t.value[len] = '\0';

            if (strcmp(t.value, "print") == 0) t.type = TOKEN_PRINT;
            else if (strcmp(t.value, "let") == 0) t.type = TOKEN_LET;
            else if (strcmp(t.value, "if") == 0) t.type = TOKEN_IF;
            else if (strcmp(t.value, "else") == 0) t.type = TOKEN_ELSE;
            else if (strcmp(t.value, "while") == 0) t.type = TOKEN_WHILE;
            else t.type = TOKEN_IDENT;

            tokens[tokenCount++] = t;
            continue;
        }

        Token t;
        t.value[0] = c;
        t.value[1] = '\0';

        if (c == '+') t.type = TOKEN_PLUS;
        else if (c == '-') t.type = TOKEN_MINUS;
        else if (c == '*') t.type = TOKEN_STAR;
        else if (c == '/') t.type = TOKEN_SLASH;
        else if (c == '(') t.type = TOKEN_LPAREN;
        else if (c == ')') t.type = TOKEN_RPAREN;
        else if (c == '{') t.type = TOKEN_LBRACE;
        else if (c == '}') t.type = TOKEN_RBRACE;
        else if (c == '>') t.type = TOKEN_GT;
        else if (c == '<') t.type = TOKEN_LT;
        else if (c == '=') {
            if (src_pos + 1 < src_len && src[src_pos + 1] == '=') {
                t.type = TOKEN_EQ;
                strcpy(t.value, "==");
                src_pos++;
            } else {
                t.type = TOKEN_ASSIGN;
            }
        } else {
            src_pos++;
            continue;
        }

        tokens[tokenCount++] = t;
        src_pos++;
    }

    Token eof;
    eof.type = TOKEN_EOF;
    strcpy(eof.value, "EOF");
    tokens[tokenCount++] = eof;
}

Token peek_token() {
    if (currentTokenIndex >= tokenCount) {
        return tokens[tokenCount - 1];
    }
    return tokens[currentTokenIndex];
}

Token next_token() {
    Token t = peek_token();
    if (currentTokenIndex < tokenCount) {
        currentTokenIndex++;
    }
    return t;
}

int parse_expression() {
    Token tok = next_token();
    int result = 0;

    if (tok.type == TOKEN_INT) {
        result = atoi(tok.value);
    } else if (tok.type == TOKEN_IDENT) {
        result = get_variable(tok.value);
    } else if (tok.type == TOKEN_LPAREN) {
        result = parse_expression();
        next_token();
    }

    Token peek = peek_token();
    while (peek.type == TOKEN_PLUS || peek.type == TOKEN_MINUS || peek.type == TOKEN_STAR || peek.type == TOKEN_SLASH) {
        next_token();
        Token next_val = next_token();
        int val = 0;
        if (next_val.type == TOKEN_INT) val = atoi(next_val.value);
        else if (next_val.type == TOKEN_IDENT) val = get_variable(next_val.value);

        if (peek.type == TOKEN_PLUS) result += val;
        else if (peek.type == TOKEN_MINUS) result -= val;
        else if (peek.type == TOKEN_STAR) result *= val;
        else if (peek.type == TOKEN_SLASH) {
            if (val == 0) {
                printf("Runtime Error: Division by zero\n");
                exit(1);
            }
            result /= val;
        }
        peek = peek_token();
    }
    return result;
}

int evaluate_condition() {
    next_token(); 
    int left = parse_expression();
    Token op = next_token();
    int right = parse_expression();
    next_token(); 

    if (op.type == TOKEN_GT) return left > right;
    if (op.type == TOKEN_LT) return left < right;
    if (op.type == TOKEN_EQ) return left == right;
    return 0;
}

void skip_block() {
    next_token(); 
    int brace_count = 1;
    while (brace_count > 0) {
        Token t = next_token();
        if (t.type == TOKEN_LBRACE) brace_count++;
        if (t.type == TOKEN_RBRACE) brace_count--;
        if (t.type == TOKEN_EOF) break;
    }
}

void execute_statements();

void interpret_statement() {
    Token tok = next_token();

    if (tok.type == TOKEN_PRINT) {
        Token next = peek_token();
        if (next.type == TOKEN_STRING) {
            next_token();
            printf("%s\n", next.value);
        } else {
            int value = parse_expression();
            printf("%d\n", value);
        }
    }
    else if (tok.type == TOKEN_LET) {
        Token name_tok = next_token();
        next_token(); 
        int value = parse_expression();
        set_variable(name_tok.value, value);
    }
    else if (tok.type == TOKEN_IF) {
        int condition = evaluate_condition();
        if (condition) {
            next_token(); 
            execute_statements();
            if (peek_token().type == TOKEN_ELSE) {
                next_token(); 
                skip_block();
            }
        } else {
            skip_block();
            if (peek_token().type == TOKEN_ELSE) {
                next_token(); 
                next_token(); 
                execute_statements();
            }
        }
    }
    else if (tok.type == TOKEN_WHILE) {
        int condition_index = currentTokenIndex;
        while (1) {
            currentTokenIndex = condition_index;
            int condition = evaluate_condition();
            if (condition) {
                next_token(); 
                execute_statements();
            } else {
                skip_block();
                break;
            }
        }
    }
    else if (tok.type == TOKEN_RBRACE || tok.type == TOKEN_EOF) {
        return;
    }
}

void execute_statements() {
    while (currentTokenIndex < tokenCount) {
        Token t = peek_token();
        if (t.type == TOKEN_RBRACE || t.type == TOKEN_EOF) {
            next_token();
            break;
        }
        interpret_statement();
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: gage <filename.gg>\n");
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (!file) {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    src_len = ftell(file);
    fseek(file, 0, SEEK_SET);

    src = malloc(src_len + 1);
    if (!src) {
        fclose(file);
        return 1;
    }
    size_t read_bytes = fread(src, 1, src_len, file);
    src[read_bytes] = '\0';
    fclose(file);

    tokenize();
    
    while (currentTokenIndex < tokenCount && tokens[currentTokenIndex].type != TOKEN_EOF) {
        interpret_statement();
    }

    free(src);
    return 0;
}
