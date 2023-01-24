#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "pandefs.h"

void gen_key(unsigned char* key) {

    srand(time(NULL)); // Seed changes only every second. Not ideal but okay for now
    for(int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand();
    }
}

void save_data(unsigned char* data, const char* dest, size_t data_size) {
    FILE* f = fopen(dest, "wb");
    fwrite(data, sizeof(char), data_size, f);
    fclose(f);
}

void get_message(char** in) {

    printf("Enter your message:\n");

    char* full_in = calloc(1, sizeof(char));

    char buffer[20];
    while(1) {

        fgets(buffer, sizeof(buffer), stdin);

        full_in = realloc(full_in, strlen(full_in) + strlen(buffer) + 1);
        strcat(full_in, buffer);

        if(buffer[strlen(buffer) - 1] == '\n') break;
    }

    *in = full_in;

}

// currently designed for encrypting 7 bit signed ascii but can be modified in the future

void encrypt(const unsigned char* key, const char* in, unsigned char* final, const size_t final_size) {

    strcpy(final, in);

    int key_counter = 0;

    for(int i = 0; i < final_size; i++) {
        if(final[i] + key[key_counter] > 255) final[i] = final[i] + key[key_counter] - 255;
        else final[i] += key[key_counter];

        if(++key_counter > KEY_SIZE - 1) key_counter = 0;
    }
}