#ifndef LINKED
#define LINKED
typedef struct muzeu {
    char denumirea[100];
    char adresa[100];
    char telefonul[10];
    int numar_exponate;
    float pret_bilet;
} Muzeu;

typedef struct node {
    Muzeu data;
    struct node* next;
} Node;

void menu();

void alloc_list(Node** first);

void select_list(Node** arr, int size, Node** first, int* index);

void read_struct(Muzeu* curr);

void read_list(Node* first);

void print_list(Node* first);

void search_node(Node* first);

void modify_node_list(Node* first);

void last_node_adress(Node* first);

int size_list(Node* first);

void swap(Node* one, Node* two);

void swap_selectable(Node* first);

void sort_list(Node* first);

void free_list(Node** first);

void add_end_list(Node** first);

void add_start_list(Node** first);

void add_after_list(Node** first);

void add_before_list(Node** first);

void delete (Node** first);

Node** split_list(Node** arr, int* size, Node* first);

void print_heads(Node** arr, int size);

Node** join_list(Node** arr, int* size, int one, int two);

void write_info(Node* first);

void read_info(Node** first);

#endif