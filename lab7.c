#include <stdio.h>
#include <string.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int size, int swaps[]) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - 1 - i; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swaps[arr[j]]++;
                swaps[arr[j + 1]]++;
            }
        }
    }
}

int bubbleSortTotal(int arr[], int size) {
    int swaps = 0;
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - 1 - i; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swaps++;
            }
        }
    }
    return swaps;
}

void selectionSort(int arr[], int size, int swaps[]) {
    for(int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for(int j = i + 1; j < size; j++) {
            if(arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i) {
            swap(&arr[i], &arr[min_idx]);
            swaps[arr[i]]++;
            swaps[arr[min_idx]]++;
        }
    }
}

int selectionSortTotal(int arr[], int size) {
    int swaps = 0;
    for(int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for(int j = i + 1; j < size; j++) {
            if(arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i) {
            swap(&arr[i], &arr[min_idx]);
            swaps++;
        }
    }
    return swaps;
}

void printSwaps(int arr[], int size, int swaps[]) {
    for (int i = 0; i < size; i++) {
        printf("%d: %d\n", arr[i], swaps[arr[i]]);
    }
}

int main() {
    int arr1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int arr2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    // After bubble sorting array, it is already sorted so we need original one
    // Copying for bubble sort total swaps
    int arr1_copy1[n1];
    int arr2_copy1[n2];
    memcpy(arr1_copy1, arr1, n1 * sizeof(int));
    memcpy(arr2_copy1, arr2, n2 * sizeof(int));
    int swaps1[100] = {0}; 
    int swaps2[100] = {0};
    // Copying for selection sort 
    int arr1_copy2[n1];
    int arr2_copy2[n2];
    memcpy(arr1_copy2, arr1, n1 * sizeof(int));
    memcpy(arr2_copy2, arr2, n2 * sizeof(int));
    // Copying for selection sort total swaps
    int arr1_copy3[n1];
    int arr2_copy3[n2];
    memcpy(arr1_copy3, arr1, n1 * sizeof(int));
    memcpy(arr2_copy3, arr2, n2 * sizeof(int));
    int swaps3[100] = {0}; 
    int swaps4[100] = {0};

    printf("array1 bubble sort:\n");
    bubbleSort(arr1, n1, swaps1);
    printSwaps(arr1, n1, swaps1);
    printf("Total swaps: %d\n", bubbleSortTotal(arr1_copy1, n1));
    printf("\n");

    printf("array2 bubble sort:\n");
    bubbleSort(arr2, n2, swaps2);
    printSwaps(arr2, n2, swaps2);
    printf("Total swaps: %d\n", bubbleSortTotal(arr2_copy1, n2));
    printf("\n");
    

    printf("array1 selection sort:\n");
    selectionSort(arr1_copy2, n1, swaps3);
    printSwaps(arr1_copy2, n1, swaps3);
    printf("Total swaps: %d\n", selectionSortTotal(arr1_copy3, n1));
    printf("\n");

    printf("array2 selection sort:\n");
    selectionSort(arr2_copy2, n2, swaps4);
    printSwaps(arr2_copy2, n2, swaps4);
    printf("Total swaps: %d\n", selectionSortTotal(arr2_copy3, n2));
    printf("\n");

    return 0;
}