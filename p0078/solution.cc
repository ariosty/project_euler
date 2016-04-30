#include <iostream>
#include <vector>
using namespace std;

int main() {
    // there is a linear time algorithm for this, which makes use of a proven result
    const int LIMIT = 100000;
    const int DIV = 1000000;
    vector<int> result(LIMIT);
    result[0] = 1;
    for (int i = 1; i < LIMIT; ++i) {
        for (int j = i; j < LIMIT; ++j) {
            result[j] += result[j - i];
            result[j] %= DIV;
        }
    }
    for (int i = 0; i < LIMIT; ++i)
        if (0 == result[i]) cout << i << endl;
    return 0;
}
