#include <stdlib.h>
#include "small_sieve.h"
#include <limits.h>
#include <string.h>
#include <stdio.h>

uint64_t *small_sieve(uint64_t limit, int *status, size_t *primeCount) {
    uint64_t *result = NULL, index = 0, size;
    *status = SIEVE_OK;
    uint32_t *prime;

    if (limit >= 2) {
        size = 4 + 4 * (limit / 32);
        printf("allocating %llu bytes\n", size);
        if ((prime = malloc(size))) {
            memset(prime, UINT_MAX, size);
        } else *status = SIEVE_OUT_OF_MEMORY;
    } else *status = SIEVE_INVALID_ARGUMENT;

    if (*status == SIEVE_OK) {
        for (uint64_t p = 2; p <= limit; p++)
            if (TestBit(prime, p)) {
                (*primeCount)++;
                for (uint64_t i = p * 2; i <= limit; i += p)
                    ClearBit(prime, i);
            }
    } else return NULL;

    if ((result = malloc(sizeof(uint64_t) * (*primeCount)))) {
        for (uint64_t i = 2; i < limit; i++)
            if (TestBit(prime, i))
                result[index++] = i;
    } else *status = SIEVE_OUT_OF_MEMORY;

    free(prime);
    return result;
}