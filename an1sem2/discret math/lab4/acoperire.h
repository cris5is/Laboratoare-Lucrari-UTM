#ifndef GRAF_ACOPERIRE
#define GRAF_ACOPERIRE
typedef struct graph {
    int** inc_mat;
    int** adi_mat;
    int** adi_list;
} Graph;
typedef struct element_queue {
    int* address;
    struct element_queue* next;
} ElementQueue;
void read_mat_inc(Graph* g, int n, int k);
void read_mat_adi(Graph* g, int n);
void read_list_adi(Graph* g, int n);
void print_inc_mat(Graph* g, int n, int k);
void print_adi_mat(Graph* g, int n);
void print_adi_list(Graph* g, int n);
void addQueue(ElementQueue** first, ElementQueue** last, int* newNode);
int* delQueue(ElementQueue** first, ElementQueue** last);

#endif