#include <stdio.h>

int main()
{
    float a = -6.3, b = 9.1;
    printf("Inainte de schimbare=> %f %f", a, b);
    float temp = a;
    a = b;
    b = temp;
    printf("\nDupa schimbare=> %f %f", a, b);
    return 0;
}