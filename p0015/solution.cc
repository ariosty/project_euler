#include <cstdint>
#include <iostream>
using namespace std;

int main(void) {
    const int SIZE = 21;
    uint64_t result[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) result[i][0] = 1;
    for (int j = 0; j < SIZE; j++) result[0][j] = 1;
    for (int i = 1; i < SIZE; i++) {
        for (int j = 1; j < SIZE; j++) {
            result[i][j] = result[i-1][j] + result[i][j-1];
        }
    }
    cout << result[SIZE-1][SIZE-1] << endl;
    return 0;
}
