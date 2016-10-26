//
// Created by js on 26.10.16.
//

#include <stdlib.h>
#include "sieve.h"

uint64_t* sieve(uint64_t limit, int* status, size_t* primeCount) {
    *status = SIEVE_OK;
    *primeCount = 0;
    uint64_t *array, *result, index = 0;

    if (limit < 1)
        *status = SIEVE_INVALID_ARGUMENT;

    if ((array = malloc(sizeof(uint64_t) * limit + 1)))
        for (uint64_t i = 0; i < limit; i++)
            array[i] = i;
    else
        *status = SIEVE_OUT_OF_MEMORY;

    if (*status != SIEVE_OK)
        return NULL;

    // by definition
    array[0] = SIEVE_NOT_PRIME;
    array[1] = SIEVE_NOT_PRIME;

    // remove multiples of 2, 3, 5, 7, 9
    for (uint64_t i = 4, j = 6, k = 10, l = 14, m = 18; i < limit; i += 2, j += 3, k+= 5, l += 7, m += 9) {
        array[i] = SIEVE_NOT_PRIME;
        if (j < limit)
            array[j] = SIEVE_NOT_PRIME;
        if (k < limit)
            array[k] = SIEVE_NOT_PRIME;
        if (l < limit)
            array[l] = SIEVE_NOT_PRIME;
        if (m < limit)
            array[m] = SIEVE_NOT_PRIME;
    }

    // count found primes
    for (uint64_t i = 0; i < limit; i++)
        if (array[i] != SIEVE_NOT_PRIME)
            *primeCount++;

    if ((result = malloc(sizeof(uint64_t) * *primeCount)))
        for (uint64_t i = 0; i < limit; i++)
            if(array[i] != SIEVE_NOT_PRIME)
                result[index++] = array[i];
    else
        *status = SIEVE_OUT_OF_MEMORY;

    free(array);
    return result;
}