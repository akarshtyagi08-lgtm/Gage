#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "lexer.h"

void tokenize(const char* source_code) {
    int i = 0;
    while (source_code[i] != '\0') {
        char current = source_code[i];

        if (isspace(current)) {
            i++;
            continue;
        }

        if (isdigit(current)) {
            printf("Found Number: ");
            while (isdigit(source_code[i])) {
                putchar(source_code[i]);
                i++;
            }
            printf("\n");
            continue;
        }

        if (isalpha(current)) {
            printf("Found Word: ");
            while (isalnum(source_code[i])) {
                putchar(source_code[i]);
                i++;
            }
            printf("\n");
            continue;
        }

        if (current == '=') {
            printf("Found Operator: =\n");
            i++;
            continue;
        }
        if (current == '{') {
            printf("Found Bracket: {\n");
            i++;
            continue;
        }
        if (current == '}') {
            printf("Found Bracket: }\n");
            i++;
            continue;
        }

        i++;
    }
}