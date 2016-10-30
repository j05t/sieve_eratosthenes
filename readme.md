Sieve of Eratosthenes C implementation.
=======================================

small_sieve() uses a bit array to mark prime number positions,
sieve() uses an unsigned char array.


SMALL_SIEVE enabled: 513 MB RAM

./sieve 4294967297
using small sieve
allocating 536870916 bytes
Primes found: 203280221

real	3m31.526s
user	3m31.020s
sys	    0m0.464s


SMALL_SIEVE disabled: 4 GB RAM

./sieve 4294967297
Primes found: 203280221

real	2m58.230s
user	2m56.992s
sys	    0m1.212s
