#include <stdlib.h>
#include <time.h>
void gage_init_random() { srand(time(NULL)); }
int gage_random(int max) { return rand() % max; }
