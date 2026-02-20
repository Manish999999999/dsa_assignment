// Question 8: Write a program to perform Bubble Sort, Selection Sort, and Insertion Sort and count comparisons and swaps.

#include <stdio.h>

// Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int comp = 0, swapCount = 0;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            comp++;
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapCount++;
            }
        }
    }
    printf("Bubble Sort: ");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\nComparisons: %d, Swaps: %d\n\n", comp, swapCount);
}

// Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    int comp = 0, swapCount = 0;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            comp++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i) {
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
            swapCount++;
        }
    }
    printf("Selection Sort: ");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\nComparisons: %d, Swaps: %d\n\n", comp, swapCount);
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    int comp = 0, swapCount = 0;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0) {
            comp++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                swapCount++;
                j--;
            } else
                break;
        }
        arr[j + 1] = key;
    }

    printf("Insertion Sort: ");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\nComparisons: %d, Swaps: %d\n\n", comp, swapCount);
}

int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr1[n], arr2[n], arr3[n];
    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }

    bubbleSort(arr1, n);
    selectionSort(arr2, n);
    insertionSort(arr3, n);

    return 0;
}
