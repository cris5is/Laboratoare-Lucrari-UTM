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

typedef struct element_stack {
    int* address;
    struct element_stack* next;
} ElementStack;

void addQueue(ElementQueue** first, ElementQueue** last, int* newNode);
int* delQueue(ElementQueue** first, ElementQueue** last);
void init_retea(Retea* r, int n);
void citire_retea(Retea* r, Graph* g);
bool bfs_flux(Retea* r, int sursa, int destinatie);
int ford_fulkerson(Retea* r, int sursa, int destinatie);
void afisare_rezultate(Retea* r, int flux_max);
void free_retea(Retea* r);

#endif