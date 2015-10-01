#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


// sieve(UPPER_BOUND, l) generates an array containing all prime numbers
//   under UPPER_BOUND in ascending order, and stores the number of prime
//   numbers in *l
// requires: upper_bound >= 2
//           l is not NULL
// effects: allocates memory: caller must free
//          modifies *l
// note: the sieve method implemented below would take even less space
//         if implemented with bitset in Java

int *sieve(const int UPPER_BOUND, int *l) {
    assert(UPPER_BOUND >= 2);
    assert(l);
    int len = (UPPER_BOUND - 1) / 2;
    bool _sieve[(UPPER_BOUND - 1) / 2];
    for (int idx = 0; idx < len; idx++)
        _sieve[idx] = true;
    for (int idx = 0; idx < len; idx++) {
        if (_sieve[idx]) {
            // actual number = 2 * idx + 3, e.g. _sieve[0] represents 3,
            //   _sieve[1] represents 5, etc.
            // the inner loop removes all idx that can be represented as
            //   p * p + 2 * n * p, where p is a prime and n is a natural
            //   number
            // the index of (2 * idx + 3) ^ 2 is:
            //   ((2 * idx + 3) ^ 2 - 3) / 2 = (4 * idx * idx + 12 * idx + 6) / 2
            //                             = 2 * idx * idx + 6 * idx + 3
            //                             = 2 * idx * (idx + 3) + 3
            int current = 2 * idx * (idx + 3) + 3;
            while (current < len) {
                _sieve[current] = false;
                current += 2 * idx + 3;
            }
        }
    }
    // see https://primes.utm.edu/howmany.html
    int prime_len = (int) (UPPER_BOUND / log(UPPER_BOUND) * (1 + 1.2762 / log(UPPER_BOUND)));
    int *result = malloc(sizeof(int) * prime_len);
    result[0] = 2;
    int prime_idx = 1;
    for (int sieve_idx = 0; sieve_idx < len; sieve_idx++)
        if (_sieve[sieve_idx])
            result[prime_idx++] = sieve_idx * 2 + 3;
    result = realloc(result, sizeof(int) * prime_idx);
    *l = prime_idx;
    return result;
}
