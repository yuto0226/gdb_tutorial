#include <stdio.h>

int arr_sum(int arr[], int size) {
    if (!arr)
        return 0;

    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];

    return sum;
}

int main(int argc, char *argvp[]) {
    int arr[] = {1, 1, 2, 3, 5, 8};
    int sum = arr_sum(arr, 6);
    printf("[+] sum = %d\n", sum);
    return 0;
}
