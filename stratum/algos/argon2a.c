#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "sysendian.h"

#include "ar2/argon2.h"
#include "ar2/cores.h"
#include "ar2/ar2-scrypt-jane.h"
#include "ar2/encoding.h"

#define _ALIGN(x) __attribute__ ((aligned(x)))

#define T_COSTS 1
#define M_COSTS 250
#define MASK 0
#define ZERO 0


const char *argon2_type2string(argon2_type type, int uppercase) {
    switch (type) {
        case Argon2_d:
            return uppercase ? "Argon2d" : "argon2d";
    }

    return NULL;
}

void argon2d(argon2_context *context) { return argon2_core(context, Argon2_d); }


int argon2_hash(const uint32_t t_cost, const uint32_t m_cost,
                const uint32_t parallelism, const void *pwd,
                const size_t pwdlen, const void *salt, const size_t saltlen,
                void *hash, const size_t hashlen, char *encoded,
                const size_t encodedlen, argon2_type type){

    argon2_context context;
    int result;
    uint8_t *out;

    context.out = (uint8_t *)out;
    context.outlen = (uint32_t)hashlen;
    context.pwd = CONST_CAST(uint8_t *)pwd;
    context.pwdlen = (uint32_t)pwdlen;
    context.salt = CONST_CAST(uint8_t *)salt;
    context.saltlen = (uint32_t)saltlen;
    context.secret = NULL;
    context.secretlen = 0;
    context.ad = NULL;
    context.adlen = 0;
    context.t_cost = t_cost;
    context.m_cost = m_cost;
    context.lanes = parallelism;
    context.threads = parallelism;
    context.allocate_cbk = NULL;
    context.free_cbk = NULL;
    context.flags = ARGON2_DEFAULT_FLAGS;
    
    result = argon2_ctx(&context, type);
    
    if (result != ARGON2_OK) {
        clear_internal_memory(out, hashlen);
        free(out);
        return result;
    }
        
    
    if (hash) {
    memcpy(hash, out, hashlen);
    }

    clear_internal_memory(out, hashlen);
    free(out);

    return ARGON2_OK;
}

int argon2d_hash(const char* hash, char* out, unsigned hashlen);


