#include "sieve.h"
#include <iostream>
#include <cstdint>
using namespace std;

int main(void) {
    const int MAX = 2000000;
    vector<int> list = primeList(MAX);
    uint64_t sum = 0;
    for (int i = 0; i < list.size(); i++) sum += list[i];
    cout << sum << endl;
    return 0;
}
