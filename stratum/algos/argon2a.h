#ifndef ARGON2A_H
#define ARGON2A_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

void argon2_hash(const uint32_t t_cost, const uint32_t m_cost,
                 const uint32_t parallelism, const void *pwd,
                 const size_t pwdlen, const void *salt,
                 const size_t saltlen, void *hash,
                 const size_t hashlen);
    

#ifdef __cplusplus
}
#endif

#endif
