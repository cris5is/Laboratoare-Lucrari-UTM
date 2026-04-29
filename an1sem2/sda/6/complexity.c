#include "complexity.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
long long qsortChecks = 0;
int compare(const void* a, const void* b) {
    qsortChecks++;
    return (*(int*)a - *(int*)b);
}

void merge(int* arr, int low, int mid, int high, Analiza* stats) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int* left = (int*)malloc(n1 * sizeof(int));
    int* right = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) left[i] = arr[low + i];
    for (int j = 0; j < n2; j++) right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        stats->checks++;
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        stats->changes++;
        k++;
    }
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
        stats->changes++;
    }
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
        stats->changes++;
    }
    free(left);
    free(right);
}

void mergeSort(int* arr, int low, int high, Analiza* stats) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid, stats);
        mergeSort(arr, mid + 1, high, stats);
        merge(arr, low, mid, high, stats);
    }
}

void heapify(int* arr, int n, int i, Analiza* stats) {
    int largest = i;
    int low = 2 * i + 1;
    int high = 2 * i + 2;

    if (low < n) {
        stats->checks++;
        if (arr[low] > arr[largest])
            largest = low;
    }
    if (high < n) {
        stats->checks++;
        if (arr[high] > arr[largest])
            largest = high;
    }

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        stats->changes++;
        heapify(arr, n, largest, stats);
    }
}

void heapSort(int* arr, int n, Analiza* stats) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i, stats);
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        stats->changes++;
        heapify(arr, i, 0, stats);
    }
}

void analizaEmpirica(int n, int type) {
    int* arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        switch (type) {
            case 1:
                printf("arr[%d]=", i);
                scanf("%d", &arr[i]);
                break;
            case 2:
                arr[i] = rand() % 1000000;
                break;
            case 3:
                arr[i] = i;
                break;
            case 4:
                arr[i] = n - i;
                break;
        }
    }

    int* arrayMerge = malloc(n * sizeof(int));
    int* arrayHeap = malloc(n * sizeof(int));
    int* arrayQuick = malloc(n * sizeof(int));
    memcpy(arrayMerge, arr, n * sizeof(int));
    memcpy(arrayHeap, arr, n * sizeof(int));
    memcpy(arrayQuick, arr, n * sizeof(int));

    Analiza mergeStats = {0}, heapStats = {0};
    clock_t start, end;
    start = clock();
    mergeSort(arrayMerge, 0, n - 1, &mergeStats);
    end = clock();
    mergeStats.ms = ((double)(end - start) * 1000.0) / CLOCKS_PER_SEC;
    start = clock();
    heapSort(arrayHeap, n, &heapStats);
    end = clock();
    heapStats.ms = ((double)(end - start) * 1000.0) / CLOCKS_PER_SEC;
    qsortChecks = 0;
    start = clock();
    qsort(arrayQuick, n, sizeof(int), compare);
    end = clock();
    double qTime_ms = ((double)(end - start) * 1000.0) / CLOCKS_PER_SEC;

    printf("\nN = %d\n", n);
    printf("%-12s | %-15s | %-12s | %-12s\n", "Algoritm", "Timp (ms)", "Comparatii", "Mutari");
    printf("%-12s | %15.6f | %-12lld | %-12lld\n", "MergeSort", mergeStats.ms, mergeStats.checks, mergeStats.changes);
    printf("%-12s | %15.6f | %-12lld | %-12lld\n", "HeapSort", heapStats.ms, heapStats.checks, heapStats.changes);
    printf("%-12s | %15.6f | %-12lld | %-12s\n", "qsort()", qTime_ms, qsortChecks, "?");

    free(arr);
    free(arrayMerge);
    free(arrayHeap);
    free(arrayQuick);
}