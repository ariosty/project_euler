#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ifstream in("matrix.txt");
    int data[80][80];
    for (int i = 0; i < 80; ++i)
        for (int j = 0; j < 80; ++j)
            // note that all ',' have been replaced by ' '
            in >> data[i][j];
    int result[80];
    for (int i = 0; i < 80; ++i) result[i] = data[i][0];
    for (int i = 1; i < 80; ++i) {
        result[0] += data[0][i];
        for (int j = 1; j < 80; ++j)
            result[j] = min(result[j], result[j-1]) + data[j][i];
        for (int j = 78; j >= 0; --j)
            result[j] = min(result[j], result[j+1] + data[j][i]);
    }
    int value = result[0];
    for (int i = 0; i < 80; ++i)
        if (result[i] < value) value = result[i];
    cout << value << endl;
    return 0;
}
