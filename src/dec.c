#include <stdio.h>
#include <string.h>
#include "pandefs.h"

int read_data(unsigned char* data, const char* dest, size_t data_size) {
    FILE* f = fopen(dest, "rb");
    if(!f) return 0;
    fread(data, sizeof(char), data_size, f);
    fclose(f);
    return 1;
}

void decrypt(const unsigned char* key, unsigned char* final, const unsigned char* enc, const size_t enc_size) {

    memcpy(final, enc, enc_size);

    int key_counter = 0;

    for(int i = 0; i < enc_size; i++) {
        if(final[i] - key[key_counter] < 0) final[i] = 255 + (final[i] - key[key_counter]);
        else final[i] -= key[key_counter];

        if(++key_counter > KEY_SIZE - 1) key_counter = 0;
    }
}