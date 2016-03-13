#include "../p0010/sieve.h"
#include <vector>
#include <iostream>
using namespace std;

int main(void) {
    const int N = 100;
    const int COUNT = 5000;
    vector<int> primes = primeList(N);
    int result[N] = {1};
    for (int i = 0; i < primes.size(); i++)
        for (int j = primes[i]; j < N; j++)
            result[j] += result[j - primes[i]];
    for (int i = 0; i < N; i++)
        if (result[i] > COUNT) {
            cout << i << endl;
            return 0;
        }
    return 1;
}
