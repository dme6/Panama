#include <stdio.h>
#include "pandefs.h"

void read_data(unsigned char* data, const char* dest, size_t data_size) {
    FILE* f = fopen(dest, "r");
    fread(data, data_size, 1, f);
    fclose(f);
}