/* C program for Insertion Sort */
#include <math.h>
#include <stdio.h>
 
void insertionSort(int arr[], int n) {
    int i, j, key;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    insertionSort(arr, sizeof(arr) / sizeof(arr[0]));
    printf("Original Array: ");
    printArray(arr, sizeof(arr) / sizeof(arr[0]));
    printf("After Sorting: ");
    printArray(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}