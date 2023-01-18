#pragma once

#define KEY_SIZE 1024
#define KEY_DEST "key.bin"
#define ENC_DEST "enc.bin"

// Data is encrypted in blocks. Blocks must be multiples of the key size.