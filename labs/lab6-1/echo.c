#include <stdio.h>

int main(int argc, char *argv[]) {
    char input[4096] = {0};

    while (scanf("%s", input) != EOF)
        printf("%s", input);

    return 0;
}