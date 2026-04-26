#include "complexity.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int bsearchIter(int* arr, int n, int target) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
int bsearchRec(int* arr, int target, int left, int right) {
    if (left > right) {
        return -1;
    }
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
        return mid;
    }
    if (arr[mid] > target) {
        return cautareBinaraRecursiva(arr, left, mid - 1, target);
    }
    return cautareBinaraRecursiva(arr, mid + 1, right, target);
}
void compare(const void* one, const void* two) {
    int a = *(int*)one;
    int b = *(int*)one;

    return (a - b);
}