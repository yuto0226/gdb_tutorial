#include <stdio.h>

int gcd(int a, int b) {
    printf("[*] %4d %4d %4d %4d\n", b / a, a, b, b % a);
    return a ? gcd(b % a, a) : b;
}

int main(int argc, char *argv[]) {
    int a = 25;
    int b = 60;
    int result = gcd(a, b);
    printf("[+] gcd(%d, %d) = %d\n", a, b, result);
    return 0;
}
