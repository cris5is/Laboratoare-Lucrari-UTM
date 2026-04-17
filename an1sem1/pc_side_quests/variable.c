#include <stdio.h>

int main()
{
    float a = 1.1, b = 3.5;
    printf("Inainte de schimbare=> %f %f", a, b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("\nDupa schimabre=> %f %f", a, b);
    return 0;
}