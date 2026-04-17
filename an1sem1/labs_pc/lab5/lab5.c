#include <stdio.h>
#include <stdlib.h>
// Să se determine minimul dintre sumele elementelor pozitive de pe diagonala principală și cea
// secundara
int sumPri(int** arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        if (arr[i][i] > 0) sum += arr[i][i];
    return sum;
}

int sumSec(int** arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        if (arr[i][size - i - 1] > 0) sum += arr[i][size - i - 1];
    return sum;
}

void min(int one, int two) {
    if (one < two)
        printf("\nMinim=%d (Principal)", one);
    else
        printf("\nMinim=%d (Secundar)", two);
}
int main() {
    int n;
    printf("\nn=");
    scanf("%d", &n);
    int** arr = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        *(arr + i) = (int*) malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", *(arr + i) + j);
    min(sumPri(arr, n), sumSec(arr, n));
    for (int i = 0; i < n; i++) free(arr[i]);
    free(arr);
    return 0;
}