#include <stdio.h>
void gage_write_file(char* name, char* data) {
    FILE *f = fopen(name, "w");
    if(f) { fprintf(f, "%s", data); fclose(f); }
}
