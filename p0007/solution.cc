#include <iostream>
using namespace std;

int main(void) {
    /*
        using the approximation pi(x) = x / (log(x) - 1) where
        pi(x) represents the number of prime numbers below x,
        we can see that 150000 looks like a good upper bound
    */
    const int UPPER = 150000;
    const int PRIME_COUNT = 10001;
    bool *sieve = new bool[UPPER];

    for (int i = 2; i < UPPER; i++) {
        if (i % 2 == 1) sieve[i] = true;
        else sieve[i] = false;
    } // for

    // raw sieve method
    for (int i = 3; i * i < UPPER; i++) {
        int current = i * i;
        while (current < UPPER) {
            sieve[current] = false;
            current += 2 * i; // even numbers have been ruled out in initialization
        } // while
    } // for

    int i = 2;
    for (int count = 1; count < PRIME_COUNT; i++) {
        if (sieve[i]) count++;
    } // for

    cout << i - 1 << endl;
    delete[] sieve;
    return 0;
} // main
