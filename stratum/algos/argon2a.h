#ifndef ARGON2A_H
#define ARGON2A_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

int argon2d_hash(const char* hash, char* out, size_t hashlen);

#ifdef __cplusplus
}
#endif

#endif
