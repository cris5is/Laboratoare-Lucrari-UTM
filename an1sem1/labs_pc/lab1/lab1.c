#include <math.h>
#include <stdio.h>

int main() {
    float x1 = 0, x2 = 0, px = 0, a = 0, b = 0, c = 0, f = 0;
    scanf("%f %f %f %f %f %f", &x1, &x2, &px, &a, &b, &c);
    for (float x = x1; x <= x2; x += px) {
        if ((x < c + a || b != 0)) {
            f = log(x) / (c + b) + x / a;
        } else if (x > c + a && b == 0) {
            f = (a - a * pow(x, 2) + pow(c, 3)) / (sin(b));
        } else {
            f = (a + x) / (pow(x, 2) - c);
        }
        printf("x=%f f(x)=%f\n", x, f);
    }
    return 0;
}