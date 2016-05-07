/*
    Note that
    (p + q) ^ 2 - p ^ 2 - (p - q) ^ 2 = p * (4 * q - p)
    Let a = p, b = 4 * q - p, we have
    1. n = a * b
    2. p - q = (3 * a - b) / 4
    3. q = (a + b) / 4
    To avoid the complication of generating divisors for a given integer,
    again, we do it reversely.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    const int LIMIT = 1000000;
    int result[LIMIT] = {0};
    int count = 0;
    for (int a = 1; a < LIMIT; ++a)
        for (int b = 1; a * b < LIMIT; ++b)
            if (3 * a > b && (a + b) % 4 == 0 && (3 * a - b) % 4 == 0)
                ++result[a * b];
    for (int i = 0; i < LIMIT; ++i)
        if (10 == result[i]) ++count;
    cout << count << endl;
    return 0;
}
