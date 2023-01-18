#pragma once

#include <stddef.h>

void gen_key(unsigned char* key);

void save_data(unsigned char* data, const char* dest, size_t data_size);

void get_message(char** in);

void encrypt(const unsigned char* key, const char* in, unsigned char* final, const size_t final_size);