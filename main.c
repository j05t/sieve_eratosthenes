#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sieve.h"


int main(int argc, char *argv[]) {
    uint64_t limit = 0, *result = NULL;
    int status = 0, print = 0;
    size_t primeCount = 0;

    if (argc == 3) {
        if (strcmp(argv[1], "-p") == 0) {
            print = 1;
        }
        limit = strtoull(argv[2], NULL, 10);
    } else if (argc == 2) {
        limit = strtoull(argv[1], NULL, 10);
    } else {
        printf("Usage: %s [-p] limit\n", argv[0]);
    }

    if (print)
        printf("will print results\n");
    printf("limit: %llu \n", limit);

    result = sieve(limit, &status, &primeCount);

    if (print)
        for (uint64_t i = 0; i < primeCount; i++)
            printf("%llu ", result[i]);
    else
        printf("\nPrimes found: %zu\n", primeCount);

    printf("\nPrimes found: %zu\n", primeCount);

    return 0;
}
