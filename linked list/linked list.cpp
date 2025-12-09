#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

/* Create new node */
Node* create(int value) {
    Node* n = (Node*)malloc(sizeof(Node));  // <--- cast added for C++ compilers
    if (n == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    n->data = value;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

/* Insert at front */
void insertFront(Node** head, int value) {
    Node* n = create(value);
    n->next = *head;
    if (*head != NULL)
        (*head)->prev = n;
    *head = n;
}

/* Insert at end */
void insertEnd(Node** head, int value) {
    Node* n = create(value);
    if (*head == NULL) {
        *head = n;
        return;
    }
    Node* t = *head;
    while (t->next != NULL)
        t = t->next;
    t->next = n;
    n->prev = t;
}

/* Print forward */
void displayForward(Node* head) {
    printf("Forward: ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

/* Print backward */
void displayBackward(Node* tail) {
    printf("Backward: ");
    while (tail != NULL) {
        printf("%d <-> ", tail->data);
        tail = tail->prev;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    insertFront(&head, 10);
    insertFront(&head, 5);
    insertEnd(&head, 20);

    /* find tail */
    Node* tail = head;
    while (tail != NULL && tail->next != NULL)
        tail = tail->next;

    displayForward(head);
    displayBackward(tail);

    return 0;
}

