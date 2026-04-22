#ifndef FLUX
#define FLUX
#include <stdbool.h>

typedef struct graph {
    int** adi_list;
} Graph;

typedef struct retea {
    int n;
    int** M_capacity;
    int** M_flux;
    int* parinte;
} Retea;

typedef struct element_queue {
    int* address;
    struct element_queue* next;
} ElementQueue;

void addQueue(ElementQueue** first, ElementQueue** last, int* newNode);
int* delQueue(ElementQueue** first, ElementQueue** last);
void readRetea(Retea* r, Graph* g, int n);
bool calcFlux(Retea* r, int sursa, int destinatie, int n);
int fordFlukerson(Retea* r, int sursa, int destinatie, int n);
void printResult(Retea* r, int flux_max, int n);
void freeMem(Retea* r, int n);

#endif