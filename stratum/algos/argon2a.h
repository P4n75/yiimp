#ifndef ARGON2A_H
#define ARGON2A_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

void WolfArgon2dAllocateCtx(void **Matrix)
{
	#ifdef _WIN32
	*((Argon2d_Block **)Matrix) = (Argon2d_Block *)_aligned_malloc(32, sizeof(Argon2d_Block) * (SEGMENT_LENGTH << 4));
	#else
	*((Argon2d_Block **)Matrix) = (Argon2d_Block *)malloc(sizeof(Argon2d_Block) * (SEGMENT_LENGTH << 4));
	posix_memalign(Matrix, 32, sizeof(Argon2d_Block) * (SEGMENT_LENGTH << 4));
	#endif
}

void WolfArgon2dFreeCtx(void *Matrix)
{
	free(Matrix);
}

#ifdef __cplusplus
}
#endif

#endif
