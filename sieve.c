//
// Created by js on 26.10.16.
//

#include <stdlib.h>
#include "sieve.h"


uint64_t *sieve(uint64_t limit, int *status, size_t *primeCount) {
    *status = SIEVE_OK;
    *primeCount = 0;
    uint64_t *result, index = 0;
    char *prime;

    if (limit < 1)
        *status = SIEVE_INVALID_ARGUMENT;

    if ((prime = malloc(sizeof(char) * (limit + 1))))
        for (uint64_t i = 0; i < limit; i++)
            prime[i] = 1;
    else
        *status = SIEVE_OUT_OF_MEMORY;

    if (*status != SIEVE_OK)
        return NULL;

    // by definition
    prime[0] = 0;
    prime[1] = 0;

    for (uint64_t p = 2; p <= limit; p++)
        if (prime[p]) {
            (*primeCount)++;
            for (uint64_t i = p * 2; i <= limit; i += p)
                prime[i] = 0;
        }

    if ((result = malloc(sizeof(uint64_t) * (*primeCount))))
        for (uint64_t i = 0; i < limit; i++)
            if (prime[i])
                result[index++] = i;
            else
                *status = SIEVE_OUT_OF_MEMORY;

    free(prime);
    return result;
}