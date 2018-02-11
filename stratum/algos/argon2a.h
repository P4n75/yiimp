#ifndef ARGON2A_H
#define ARGON2A_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

void argon2_hash(const char* hash, char* out, uint32_t hashlen);

#ifdef __cplusplus
}
#endif

#endif
