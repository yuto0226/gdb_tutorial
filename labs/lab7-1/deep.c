#include <stdio.h>

int third_function(int x) {
    int *ptr = NULL;
    *ptr = x;  // Segmentation fault
    return 0;
}

int second_function(int x) {
    return third_function(x);
}

int first_function(int x) {
    return second_function(x);
}

int main() {
    int value = 10;
    first_function(value);
    return 0;
}
