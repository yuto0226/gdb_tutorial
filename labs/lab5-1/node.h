
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
    struct node *prev;
} node_t;

void node_init(node_t *n) {
    n->prev = n;
    n->next = n;
}

node_t *node_new(int value) {
    node_t *n = (node_t *) malloc(sizeof(*n));
    n->value = value;
    node_init(n);
    return n;
}

void __node_add(node_t *new_node, node_t *prev, node_t *next) {
    next->prev = new_node;
    new_node->next = next;
    new_node->prev = prev;
    prev->next = new_node;
}

void node_add(node_t *new_node, node_t *head) {
    __node_add(new_node, head, head->next);
}

void node_add_tail(node_t *new_node, node_t *head) {
    __node_add(new_node, head->prev, head);
}

#define node_for_each(entry, head) \
    for ((entry) = (head)->next; (entry) != (head); (entry) = (entry)->next)
