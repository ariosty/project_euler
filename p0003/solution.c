#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <math.h>

int *sieve(const int, int *);

int main(void) {
    int64_t N = 600851475143;
    int UPPER_BOUND = sqrt(N);
    int len = 0;
    int *primes = sieve(10000, &len);
    for (int idx = len - 1; idx >= 0; idx--) {
        if (N % primes[idx] == 0) {
            printf("%d\n", primes[idx]);
        }
    }
    free(primes);
    return 0;
}
