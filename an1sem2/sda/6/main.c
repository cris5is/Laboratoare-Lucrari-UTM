#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "complexity.h"

int main() {
    struct timespec start, end;
    timespec_get(&start, TIME_UTC);
    // Code to measure
    timespec_get(&end, TIME_UTC);

    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Elapsed time: %f seconds\n", elapsed);
    return 0;
}