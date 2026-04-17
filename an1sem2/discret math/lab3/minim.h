#ifndef FORD_BELLMAN
#define FORD_BELLMAN
typedef struct graph {
    int** adi_mat;
    int** adi_list;
} Graph;
typedef struct element_stack {
    int* address;
    struct element_stack* next;
} ElementStack;
void push(ElementStack** top, int* newNode);
int* pop(ElementStack** top);
void readMat(Graph* g, int n);
void printMat(Graph* g, int n);
void printDrumuriF(Graph* g, int* h, int curent, int final, int* drum, int pas, int n);
void printDrumuriBK(Graph* g, int* V, int curent, int final, int* drum, int pas, int n);
void fordMinim(Graph* g, int n);
void bellman_kalabaMinim(Graph* g, int n);
void writeInfo(Graph* g, int n);
void freeMem(Graph* g, int n);
#endif