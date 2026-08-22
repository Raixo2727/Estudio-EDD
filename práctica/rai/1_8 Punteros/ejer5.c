#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int id;
    char name[30];
    struct node *next;
} node;

node* create_node(int cant) {
    node *head = NULL;
    for (int i=0; i< cant; i++) {
        node *new_node = calloc(1, sizeof(struct node));

        new_node->id = i +1;
        snprintf(new_node->name, sizeof(new_node->name), "node%d", i);

        new_node->next = head;
        head = new_node;
    }
    return head;
}

node* find_node(int id, node *head) {
    node *current = head;
    node *prev = NULL;

    while (current!= NULL && current->id != id) {
        prev = current;
        current = current -> next;
    }

    if (current == NULL) {
        return head;
    }

    if (prev != NULL) {
        prev->next = current->next;
        current->next = head;
        head = current;
    }

    return head;
}

void print_list(node *head) {
    node *temp = head;
    while (temp != NULL) {
        printf("[%s | ID: %d] -> ", temp->name, temp->id);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main () {
    srand((unsigned int)time(NULL));

    int cant = 5;
    int search_id;

    // 1. Create the list
    node *head = create_node(cant);

    // 2. Show initial list
    printf("Initial list:\n");
    print_list(head);

    // 3. Search and move to front
    printf("\nEnter ID to search and move to front: ");
    scanf("%d", &search_id);

    head = find_node(search_id, head);

    // 4. Show list after moving
    printf("\nList after search:\n");
    print_list(head);

    return 0;

};