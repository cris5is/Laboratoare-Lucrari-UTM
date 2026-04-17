#include <stdio.h>

int main() {
    int a = 0, b = 0;
    printf("\na=");
    scanf("%d", &a);
    printf("\nb=");
    scanf("%d", &b);
    int sum_a = 0, sum_b = 0;
    for (int i = 1; i <= a / 2; i++) {
        if (a % i == 0) sum_a += i;
    }
    for (int i = 1; i <= b / 2; i++) {
        if (b % i == 0) sum_b += i;
    }

    if (sum_a == b && sum_b == a)
        printf("Da");
    else
        printf("Nu");
    return 0;
}