// Question 4: Write a program to create a doubly linked list and perform insertion and deletion.

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insert at end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Delete a node by value
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    while (temp != NULL) {
        if (temp->data == key) {
            if (temp->prev != NULL)
                temp->prev->next = temp->next;
            else
                *head = temp->next; // deleting head
            if (temp->next != NULL)
                temp->next->prev = temp->prev;
            free(temp);
            printf("%d deleted from list.\n", key);
            return;
        }
        temp = temp->next;
    }
    printf("%d not found in list.\n", key);
}

// Print list forward
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, value, del;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    printf("List: ");
    printList(head);

    printf("Enter value to delete: ");
    scanf("%d", &del);
    deleteNode(&head, del);

    printf("Updated list: ");
    printList(head);

    return 0;
}
