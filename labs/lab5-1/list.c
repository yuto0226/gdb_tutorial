#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int rand_num(int start, int end) {
    return (rand() % (end - start + 1)) + start;
}

int main() {
    node_t *head = node_new(-1);

    srand(0xFFFFFFFF);
    for (int i = 0; i < 10; i++) {
        node_t *n = node_new(rand_num(1, 100));
        node_add(n, head);
    }

    node_t *curr;
    node_for_each(curr, head) {
        printf("%d ", curr->value);
    }
    printf("\n");

    return 0;
}