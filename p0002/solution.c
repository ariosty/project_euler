#include <stdio.h>

int main(void) {
    int UPPER_BOUND = 4000000;
    int fib_1 = 2, fib_2 = 3, fib_3 = 5;
    int result = 0;
    while (fib_1 < UPPER_BOUND) {
        result += fib_1;
        fib_1 = fib_2 + fib_3;
        fib_2 = fib_3 + fib_1;
        fib_3 = fib_1 + fib_2;
    }
    printf("%d\n", result);
    return 0;
}
