//
// Created by js on 26.10.16.
//

#ifndef SIEVEERATOSTHENES_SIEVE_H
#define SIEVEERATOSTHENES_SIEVE_H

#define SIEVE_OK 0
#define SIEVE_INVALID_ARGUMENT 1
#define SIEVE_OUT_OF_MEMORY 2
#define SIEVE_NOT_PRIME 0

typedef unsigned long long uint64_t;

uint64_t* sieve(uint64_t limit, int* status, size_t* primeCount);

#endif //SIEVEERATOSTHENES_SIEVE_H
