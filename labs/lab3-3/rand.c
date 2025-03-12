#include <stdio.h>
#include <stdlib.h>

int rand_num(int start, int end) {
    return (rand() % (end - start + 1)) + start;
}

int main(int argc, char *argv[]) {
    srand(0xFFFFFFFF);

    int number = 0xcafebabe;
    number = rand_num(1, 100);
    number = 0xdeadbeef;

    printf("[+] number = %d\n", number);

    return 0;
}
