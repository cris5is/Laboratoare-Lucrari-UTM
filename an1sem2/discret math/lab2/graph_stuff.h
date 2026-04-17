#ifndef GRAPH_DFS_BFS
#define GRAPH_DFS_BFS
typedef struct graph {
    int** adi_list;
} Graph;
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
void push(ElementStack** top, int* newNode);
int* pop(ElementStack** top);
void print_adi_list(Graph* g, int n);
void read_list_adi(Graph* g, int n);
void freeMem(Graph* g, int n);
void adancime(Graph* g, int n, ElementStack** top, int needed);
void latime(Graph* g, int n, ElementQueue** FA1First, ElementQueue** FA1Last, ElementQueue** FA2First, ElementQueue** FA2Last, int needed);
void writeInfo(Graph* g, int n);
#endif