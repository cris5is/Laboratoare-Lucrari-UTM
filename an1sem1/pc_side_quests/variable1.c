#include <stdio.h>
#include <math.h>
int main()
{

    float a = -5.2, b = 2.4;
    printf("Inainte de schimbare=> %f %f", a, b);
    a = a - b;
    b = a + b;
    a = b - a;

    printf("\nDupa schimbare=> %f %f", a, b);
    return 0;
}
