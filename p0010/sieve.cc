#include <vector>
#include <cassert>
#include <cmath>
#include "sieve.h"
using namespace std;

// see sieve.h for documentation

vector<int> primeList(const int MAX) {
    assert(MAX > 2);
    const int SIZE = (MAX - 1) / 2;
    vector<bool> sieve(SIZE);
    for (int i = 0; i < SIZE; i++) sieve[i] = true;
    vector<int> result;
    result.push_back(2);
    double upper = (sqrt(MAX) - 3) / 2;
    for (int i = 0; i < upper; i++) {
        if (sieve[i]) {
            int current = 2 * i * (i + 3) + 3;
            while (current < SIZE) {
                sieve[current] = false;
                current += 2 * i + 3;
            }
        }
    }
    for (int i = 0; i < SIZE; i++)
        if (sieve[i]) result.push_back(2 * i + 3);
    return result;
}
