#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sieve.h"


int main(int argc, char *argv[]) {
    uint64_t limit, *result;
    int status, print = 0;
    size_t primeCount;

    if (argc == 1) {
        limit = atoll(argv[1]);
    } else if (argc == 2) {
        if (strcmp("-p", argv[1]) == 0)
            print = 1;
        limit = atoll(argv[1]);
    } else {
        printf("Usage: sieve [-p] limit");
    }


    result = sieve(limit, &status, &primeCount);

    if(print)
        for (uint64_t i = 0; i < limit; i++)
            printf("%d ", result[i]);
    else
        printf("Primes found: %d", primeCount);

    free(result);
    return 0;
}
