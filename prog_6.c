// Question 6: Write a program to implement Min Heap and Max Heap operations (insert and display).

#include <stdio.h>
#define MAX 100

int heap[MAX];
int size = 0;

// Swap two numbers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Min Heap insertion
void insertMinHeap(int value) {
    int i = size;
    heap[size++] = value;
    while (i != 0 && heap[i] < heap[(i - 1) / 2]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Max Heap insertion
void insertMaxHeap(int value) {
    int i = size;
    heap[size++] = value;
    while (i != 0 && heap[i] > heap[(i - 1) / 2]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Display heap
void displayHeap() {
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    int n, value, choice;

    printf("Enter number of elements to insert: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        printf("Insert into Min Heap (1) or Max Heap (2)? ");
        scanf("%d", &choice);
        if (choice == 1)
            insertMinHeap(value);
        else if (choice == 2)
            insertMaxHeap(value);
        else
            printf("Invalid choice\n");
    }

    printf("Heap elements: ");
    displayHeap();

    return 0;
}
