#include <stdio.h>
#include <stdlib.h>
#include "lexer.c"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Error: Please provide a Gage source file.\n");
        printf("Usage: ./gage <filename>.gg\n");
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* source_code = malloc(file_size + 1);
    fread(source_code, 1, file_size, file);
    source_code[file_size] = 0;
    fclose(file);

    tokenize(source_code);

    free(source_code);
    return 0;
}
