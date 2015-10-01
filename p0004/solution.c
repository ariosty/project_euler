#include <stdio.h>
#include <stdbool.h>
#include <assert.h>


// is_palindrome(num) determines whether a given num is a palindrome
// requires: num >= 0
// time: O(log(num))

bool is_palindrome(const int num) {
    assert(num >= 0);
    int reverse = 0;
    int copy = num;
    while (copy > 0) {
        reverse = reverse * 10 + copy % 10;
        copy /= 10;
    }
    return reverse == num;
}


int main(void) {
    int cand[200] = {0};
    int idx = 0;
    for (int i = 901; i < 1000; i += 10) {
        for (int j = 909; j < 1000; j += 10) {
            int product = i * j;
            if (is_palindrome(product) && product >= 900000)
                cand[idx++] = product;
        }
    }
    for (int i = 903; i < 1000; i += 10) {
        for (int j = i; j < 1000; j += 10) {
            int product = i * j;
            if (is_palindrome(product) && product >= 900000)
                cand[idx++] = product;
        }
    }
    int max = 0;
    for (int i = 0; i < idx; i++)
        if (cand[i] > max)
            max = cand[i];
    printf("%d\n", max);
    return 0;
}
