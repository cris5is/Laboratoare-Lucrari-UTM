#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structing.h"
int main() {
    Muzeu* arr_muzee = NULL;
    int size = 0;
    int option;

    do {
        menu();
        if (scanf("%d", &option) != 1) {
            printf("Optiune invalida\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');
        switch (option) {
            case 1:
                arr_muzee = aloc_mem_struct(&size);
                break;
            case 2:
                insert_struct(arr_muzee, size);
                break;
            case 3:
                print_struct(arr_muzee, size);
                break;
            case 4:
                search_obj(arr_muzee, size);
                break;
            case 5:
                modify_obj_struct(arr_muzee, size);
                break;
            case 6:
                switch_i_j(arr_muzee, size);
                break;
            case 7:
                sort_struct(arr_muzee, size);
                break;
            case 8:
                arr_muzee = add_end_struct(arr_muzee, &size);
                break;
            case 9:
                arr_muzee = add_start_struct(arr_muzee, &size);
                break;
            case 10:
                arr_muzee = add_after_i_struct(arr_muzee, &size);
                break;
            case 11:
                arr_muzee = add_before_i_struct(arr_muzee, &size);
                break;

            case 12:
                arr_muzee = delete_obj(arr_muzee, &size);
                break;
            case 13:
                write_info(arr_muzee, size);
                break;
            case 14:
                arr_muzee = read_info(arr_muzee, &size);
                break;
            case 15:
                arr_muzee = free_struct(arr_muzee, &size);
                break;
            case 0:
                break;
            default:
                printf("Alegeti o optiune valabila: \n");
        }
    } while (option != 0);

    arr_muzee = free_struct(arr_muzee, &size);
    return 0;
}