#include <stdio.h>

int main() {
    // 1) 陣列越界示範
    int scores[3] = {80, 90, 100};

    int totalScores = 0;
    int totalStudents = 0;
    for (int i = 0; i < 4; i++) {
        totalScores += scores[i];
        printf("[+] %d th score: %d\n", scores[i]);
    }

    int average = totalScores / totalStudents;
    printf("average score: %d\n", average);

    int *p = NULL;
    *p = 5;

    printf("this line won't be executed\n");

    return 0;
}
