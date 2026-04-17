#include <stdio.h>

int main() {
    int n, m;
    printf("n=");
    scanf("%d", &n);
    printf("\nm=");
    scanf("%d", &m);
    printf("\n");
    int arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("INAINTE DE ORDONARE\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int count_i = 1, value_i, max_i = 0;
            for (int a = 0; a < m; a++) {
                value_i = arr[i][a];
                for (int b = 0; b < m; b++)
                    if (b != a && arr[i][b] == value_i) count_i++;
                if (count_i > max_i) max_i = count_i;
                count_i = 1;
            }

            int count_j = 1, value_j, max_j = 0;
            for (int a = 0; a < m; a++) {
                value_j = arr[j][a];
                for (int b = 0; b < m; b++)
                    if (b != a && arr[j][b] == value_j) count_j++;
                if (count_j > max_j) max_j = count_j;
                count_j = 1;
            }

            if (max_j < max_i) {
                for (int g = 0; g < m; g++) {
                    int t = arr[i][g];
                    arr[i][g] = arr[j][g];
                    arr[j][g] = t;
                }
            }
        }
    }
    printf("DUPA ORDONARE\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}