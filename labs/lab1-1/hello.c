#include <stdio.h>
#include <string.h>

const char key[] = "ttussc";
char secret[] = "\x3c\x11\x19\x1f\x1c\x4f\x54\x03\x1a\x01\x1f\x07\x55";

int main(int argc, char *argv[]) {
    int key_len = strlen(key);
    int secret_len = strlen(secret);
    for (int i = 0, j = 0; i < secret_len; i++, j++)
        secret[i] ^= key[j % key_len];

    // for(int i = 0;i < secret_len;i++)
    //     printf("\\x%02x", secret[i]);
    // printf("\n");

    printf("%s\n", secret);
    return 0;
}
