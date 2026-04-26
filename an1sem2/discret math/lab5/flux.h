#ifndef FLUX
#define FLUX
#include <stdbool.h>

typedef struct retea {
    int** M_capacity;
    int** M_flux;
    int* root;
} Retea;

typedef struct element_queue {
    int* address;
    struct element_queue* next;
} ElementQueue;

void addQueue(ElementQueue** first, ElementQueue** last, int* newNode);
int* delQueue(ElementQueue** first, ElementQueue** last);
void readRetea(Retea* r, int n, int** vizitat, int** nodes);
bool calcFlux(Retea* r, int sursa, int destinatie, int n, int** vizitat, int** nodes);
int fordFlukerson(Retea* r, int sursa, int destinatie, int n, int** vizitat, int** nodes);
void printResult(Retea* r, int flux_max, int n);
void freeMem(Retea* r, int n);

#endif