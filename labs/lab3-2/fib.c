#include <stdio.h>

int fib_recursion(int n) {
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;

    return fib_recursion(n - 1) + fib_recursion(n - 2);
}

int fib_iteration(int n) {
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;

    int prev = 0, fib = 1;
    for (int i = 0; i <= n; i++) {
        int tmp = fib;
        fib += prev;
        prev = tmp;
    }
    return fib;
}

int main(int argc, char *argv[]) {
    int fib_r = fib_recursion(10);
    int fib_i = fib_iteration(10);
    printf("[+] fib_r = %d, fib_i = %d\n", fib_r, fib_i);

    return 0;
}
