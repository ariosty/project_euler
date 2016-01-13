#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include "../p0010/sieve.h"
using namespace std;

// return the number of divisors of n
// requires: n > 1

int countDivisor(int n, const vector<int> &primes) {
    assert(n > 1);
    vector<int> exponent;
    int i = 0, copy = n, current = 0;
    while (i < primes.size() && primes[i] < sqrt(n)) {
        while (0 == copy % primes[i]) {
            copy /= primes[i];
            current++;
        }
        exponent.push_back(current);
        current = 0;
        i++;
    }
    int result = 1;
    for (int j = 0; j < exponent.size(); j++) {
        result *= exponent[j] + 1;
    }
    if (copy > 1) result *= 2;
    return result;
}

int main(void) {
    vector<int> primes = primeList(10000);
    for (int n = 7; n < 20000; n++) {
        int numDiv = 0;
        if (0 == n % 2) {
            numDiv = countDivisor(n / 2, primes) * countDivisor(n + 1, primes);
            if (numDiv > 500) {
                cout << n / 2 * (n + 1) << endl;
                return 0;
            }
        } else {
            numDiv = countDivisor((n + 1) / 2, primes) * countDivisor(n, primes);
            if (numDiv > 500) {
                cout << (n + 1) / 2 * n << endl;
                return 0;
            }
        }
    }
    return 0;
}
