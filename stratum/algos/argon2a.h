#ifndef ARGON2A_H
#define ARGON2A_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

void Argon2dFillSingleBlock(Argon2d_Block *State, Argon2d_Block *RefBlock, Argon2d_Block *NextBlock);

#ifdef __cplusplus
}
#endif

#endif
