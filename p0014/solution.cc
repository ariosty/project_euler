#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

int main(void) {
    int64_t maxStep = 0, maxNum = 0, temp = 0;
    for (int64_t n = 500001; n < 1000000; n++) {
        temp = 1;
        int64_t copy = n;
        while (copy > 1) {
            if (0 == copy % 2) {
                copy /= 2;
            } else {
                copy = copy * 3 + 1;
            }
            temp++;
        }
        if (temp > maxStep) {
            maxStep = temp;
            maxNum = n;
        }
    }
    cout << maxNum << endl;
    return 0;
}
