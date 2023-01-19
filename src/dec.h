#pragma once

#include <stddef.h>

int read_data(unsigned char* data, const char* dest, size_t data_size);

void decrypt(const unsigned char* key, unsigned char* final, const unsigned char* enc, const size_t enc_size);