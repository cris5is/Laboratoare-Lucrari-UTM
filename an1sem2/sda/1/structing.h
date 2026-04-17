#ifndef STRUCTUS
#define STRUCTUS
typedef struct Muzeu {
    char denumirea[100];
    char adresa[100];
    char telefonul[10];
    int numar_exponate;
    float pret_bilet;
} Muzeu;

void menu();

Muzeu* aloc_mem_struct(int* size);  //

void read_struct(Muzeu* curr);  //

void insert_struct(Muzeu* curr, int size);  //

void print_struct_by_i(Muzeu* curr, int i);  //

void print_struct(Muzeu* curr, int size);  //

Muzeu* add_start_struct(Muzeu* curr, int* size);  // #

Muzeu* add_end_struct(Muzeu* curr, int* size);  //

Muzeu* add_before_i_struct(Muzeu* curr, int* size);  //

Muzeu* add_after_i_struct(Muzeu* curr, int* size);  //

void switch_i_j(Muzeu* curr, int size);  // #

Muzeu* modify_obj_struct(Muzeu* curr, int size);  //

void search_obj(Muzeu* curr, int size);  //

int diff_struct(const void* a, const void* b);  //

void sort_struct(Muzeu* curr, int size);  //

void write_info(Muzeu* curr, int size);  // #

Muzeu* read_info(Muzeu* curr, int* size);  // #

Muzeu* delete_obj(Muzeu* curr, int* size);  //

Muzeu* free_struct(Muzeu* curr, int* size);  //
#endif