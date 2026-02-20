// Question 3: Write a program to create a singly linked list and print its elements in reverse order using recursion.

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print list in reverse using recursion
void printReverse(struct Node* head) {
    if (head == NULL)
        return;
    printReverse(head->next);
    printf("%d ", head->data);
}

int main() {
    struct Node* head = NULL;
    int n, value, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    printf("Linked List in reverse: ");
    printReverse(head);
    printf("\n");

    return 0;
}
