#define SIEVE_OK 0
#define SIEVE_INVALID_ARGUMENT 1
#define SIEVE_OUT_OF_MEMORY 2

#define SetBit(A,k)     ( A[(k/32)] |= (1 << (k%32)) )
#define ClearBit(A,k)   ( A[(k/32)] &= ~(1 << (k%32)) )
#define TestBit(A,k)    ( A[(k/32)] & (1 << (k%32)) )

typedef unsigned long long uint64_t;
typedef unsigned int uint32_t;

uint64_t *small_sieve(uint64_t limit, int *status, size_t *primeCount);

