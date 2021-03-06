#include <stdlib.h>
#include <string.h>
#include "sieve.h"


uint64_t *sieve(uint64_t limit, int *status, size_t *primeCount) {
    uint64_t *result = NULL, index = 0, size;
    unsigned char *prime;
    *status = SIEVE_OK;

    if (limit >= 2) {
        size = sizeof(unsigned char) * (limit + 1);

        if ((prime = malloc(size))) {
            memset(prime, 1, size);
        } else *status = SIEVE_OUT_OF_MEMORY;
    } else *status = SIEVE_INVALID_ARGUMENT;

    if (*status == SIEVE_OK) {
        for (uint64_t p = 2; p <= limit; p++)
            if (prime[p]) {
                (*primeCount)++;
                for (uint64_t i = p * 2; i <= limit; i += p)
                    prime[i] = 0;
            }
    } else return NULL;

    if ((result = malloc(sizeof(uint64_t) * (*primeCount)))) {
        for (uint64_t i = 2; i < limit; i++)
            if (prime[i])
                result[index++] = i;
    } else *status = SIEVE_OUT_OF_MEMORY;

    free(prime);
    return result;
}