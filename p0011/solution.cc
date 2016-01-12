#include <iostream>
#include <fstream>
using namespace std;

int main(void) {
    int data[20][20];
    ifstream in("input.txt");
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            in >> data[i][j];
        }
    }
    int max = 0;
    // rows
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 16; j++) {
            int temp = data[i][j] * data[i][j+1] * data[i][j+2] * data[i][j+3];
            if (temp > max) max = temp;
        }
    }
    // columns
    for (int j = 0; j < 20; j++) {
        for (int i = 0; i < 16; i++) {
            int temp = data[i][j] * data[i+1][j] * data[i+2][j] * data[i+3][j];
            if (temp > max) max = temp;
        }
    }
    // diagonals
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            int temp = data[i][j] * data[i+1][j+1] * data[i+2][j+2] * data[i+3][j+3];
            if (temp > max) max = temp;
        }
    }
    for (int i = 0; i < 16; i++) {
        for (int j = 4; j < 20; j++) {
            int temp = data[i][j] * data[i+1][j-1] * data[i+2][j-2] * data[i+3][j-3];
            if (temp > max) max = temp;
        }
    }
    cout << max << endl;
    return 0;
}
