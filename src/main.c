#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pandefs.h"
#include "enc.h"
#include "dec.h"

void enc_choice() {

    unsigned char key[KEY_SIZE];
    gen_key(key);
    save_data(key, KEY_DEST, sizeof(key)); // save to file

    puts("Key saved to key.bin");
    
    puts("Key:");
    for(int i = 0; i < sizeof(key); i++) {
        printf("%X ", key[i]);
    }

    printf("\n");

    char* in;
    get_message(&in);

    int blocks = 0;
    while(strlen(in) + 1 > blocks * KEY_SIZE) blocks++;

    unsigned char final[blocks * KEY_SIZE]; // allowed since c89 i think
    memset(final, 0, sizeof(final));

    encrypt(key, in, final, sizeof(final));

    puts("Original: ");
    for(int i = 0; i < strlen(in) + 1; i++) {
        printf("%X ", in[i]);
    }
    printf("\n");

    save_data(final, ENC_DEST, sizeof(final));
    puts("Encrypted message saved to enc.bin");

    puts("Encrypted: ");
    for(int i = 0; i < sizeof(final); i++) {
        printf("%X ", final[i]);
    }
    printf("\n");

    free(in);
}

void dec_choice() {

    unsigned char key[KEY_SIZE];
    read_data(key, KEY_DEST, sizeof(key));

}

int main() {
    puts("Welcome to Panama. Encrypt (1) or decrypt (2)?");
    char choice = getchar();

    int temp;
    do {
        temp = getchar();
    } while(temp != EOF && temp != '\n'); // clear everything in stdin

    switch(choice) {
        case '1': enc_choice(); break;
        case '2': dec_choice(); break;
        default: puts("Invalid"); break;
    }
}