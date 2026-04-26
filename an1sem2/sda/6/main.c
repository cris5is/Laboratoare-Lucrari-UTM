#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "complexity.h"

int main() {
    struct timespec start, end;
    int option = 0;
    timespec_get(&start, TIME_UTC);
    // Code to measure
    timespec_get(&end, TIME_UTC);

    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Elapsed time: %f seconds\n", elapsed);
    printf("Binary Search (Iterative) VS. \nBinary Search (Recursive) VS. \nBinary Search (Built-in)\n");
    printf("    1. Tabel demonstrativ de `n` elemente [5,20]\n");
    printf("    2. Tabloul cu valori aleatorii (n=10000, n=100000, n=1000000).\n");
    printf("    3. Tabloul sortat crescator (n=10000, n=100000, n=1000000).\n");
    printf("    4. Tabloul sortat descrescator (n=10000, n=100000, n=1000000).\n");
    printf("    5. Analiza empirica a funcției de cautare bsearch() din biblioteca standard a limbajului C.\n");
    printf("    6. Iesire.\n");
    return 0;
}