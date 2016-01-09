#include <iostream>
#include <fstream>
#define __STDC_FORMAT_MACROS
#include <cstdint>
#include <vector>
#include <cstdio>
using namespace std;

const int LENGTH = 13;

/*
    return the index of the start of next sequence of length LENGTH, and
    contains only non-zero digits, or -1 if such sequence does not exist
*/

int nextStart(int start, vector<char> &digits) {
    bool nonZero = false;
    int next = start + 1;
    while (!nonZero && next + LENGTH < digits.size()) {
        int i;
        for (i = 0; i < LENGTH; i++) {
            if (0 == digits[next + i]) {
                next += i + 1;
                break;
            }
        }
        if (LENGTH == i) nonZero = true;
    }
    return ((next + LENGTH >= digits.size()) ? -1 : next);
}

int main(void) {
    ifstream in("input.txt");
    vector<char> digits;
    char c;
    while (in >> c) digits.push_back(c - '0');
    int64_t max = 1;
    for (int i = 0; i < LENGTH; i++) max *= digits[i];
    int head = 0;
    while (head >= 0) {
        head = nextStart(head, digits);
        if (head < 0) break;
        int64_t current = 1;
        for (int i = 0; i < LENGTH; i++) current *= digits[head + i];
        if (current > max) max = current;
    }
    cout << max << endl;
    return 0;
}
