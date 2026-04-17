#ifndef BINARY_TREE
#define BINARY_TREE
typedef struct muzeu {
    char denumirea[100];
    char adresa[100];
    char telefonul[10];
    int numar_exponate;
    float pret_bilet;
} Muzeu;

typedef struct node {
    Muzeu data;
    struct node* left;
    struct node* right;
} Node;

typedef struct element_queue {
    Node* address;
    struct element_queue* next;
} ElementQueue;

typedef struct element_stack {
    Node* address;
    struct element_stack* next;
} ElementStack;

void Menu();
void read_struct(Muzeu* curr);

void addQueue(ElementQueue** first, ElementQueue** last, Node* newNode);
Node* delQueue(ElementQueue** first, ElementQueue** last);

void push(ElementStack** top, Node* newNode);
Node* pop(ElementStack** top);

void createQueue(ElementQueue** first, ElementQueue** last, Node** root);
void createStack(ElementStack** top, Node** root);

void showQueue(ElementQueue** first, ElementQueue** last, Node* root);
void showStack(ElementStack** top, Node* root);

void searchQueue(ElementQueue** first, ElementQueue** last, Node* root);
void searchStack(ElementStack** top, Node* root);

void modifyQueue(ElementQueue** first, ElementQueue** last, Node* root);
void modifyStack(ElementStack** top, Node* root);

int sizeQueue(ElementQueue** first, ElementQueue** last, Node* root);
int sizeStack(ElementStack** top, Node* root);

void heightQueue(ElementQueue** first, ElementQueue** last, Node* root);
void heightStack(ElementStack** top, Node* root);

void freeQueue(ElementQueue** first, ElementQueue** last, Node** root);
void freeStack(ElementStack** top, Node** root);

#endif