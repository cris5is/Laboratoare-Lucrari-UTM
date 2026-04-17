#include <limits.h>
#include <stdio.h>
int main() {
    int n = 0;
    printf("n=");
    scanf("%d", &n);
    float arr[n];
    for (int i = 0; i < n; i++) {
        printf("\narr[%d]=", i);
        scanf("%f", &arr[i]);
    }
    int min_count = 1, count = 0;
    float min = INT_MAX, media = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            media += arr[i];
            count++;
        }
        if (arr[i] < min) {
            min = arr[i];
            min_count = 1;
        } else if (arr[i] == min)
            min_count++;
    }
    media /= count;
    printf("\nMinim=%.2f de %d ori gasit , media=%.3f", min, min_count, media);

    return 0;
}