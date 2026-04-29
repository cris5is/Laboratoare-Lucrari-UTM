#ifndef ANALIZA_EMPIRICA
#define ANALIZA_EMPIRICA

typedef struct {
    long long checks;
    long long changes;
    double ms;
} Analiza;

extern long long qsortChecks;
int compare(const void* a, const void* b);
void merge(int* arr, int low, int mid, int high, Analiza* res);
void mergeSort(int* arr, int low, int high, Analiza* res);
void heapify(int* arr, int n, int i, Analiza* res);
void heapSort(int* arr, int n, Analiza* res);
void analizaEmpirica(int n, int type);
#endif