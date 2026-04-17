#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"
int main()
{
    Node** arr = (Node**)malloc(sizeof(Node*));
    int size = 1;
    Node* first = NULL, * choice1 = NULL, * choice2 = NULL;
    int one = 0, two = 0;
    int option;

    do
    {
        menu();
        if (scanf("%d", &option) != 1)
        {
            printf("Optiune invalida\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');
        switch (option)
        {
            case 1:
                alloc_list(&first);
                arr[0] = first;
                one = 0;
                break;
            case 2:
                read_list(first);
                break;
            case 3:
                select_list(arr, size, &choice1, &one);
                print_list(choice1);
                break;
            case 4:
                select_list(arr, size, &choice1, &one);
                search_node(choice1);
                break;
            case 5:
                select_list(arr, size, &choice1, &one);
                modify_node_list(choice1);
                break;
            case 6:
                select_list(arr, size, &choice1, &one);
                last_node_adress(choice1);
                break;
            case 7:
                select_list(arr, size, &choice1, &one);
                printf("Size of list=%d\n", size_list(choice1));
                break;
            case 8:
                select_list(arr, size, &choice1, &one);
                swap_selectable(choice1);
                break;
            case 9:
                select_list(arr, size, &choice1, &one);
                sort_list(choice1);
                break;
            case 10:
                select_list(arr, size, &choice1, &one);
                add_end_list(&choice1);
                break;
            case 11:
                select_list(arr, size, &choice1, &one);
                add_start_list(&choice1);
                arr[one] = choice1;
                break;
            case 12:
                select_list(arr, size, &choice1, &one);
                add_after_list(&choice1);
                break;
            case 13:
                select_list(arr, size, &choice1, &one);
                add_before_list(&choice1);
                arr[one] = choice1;
                break;
            case 14:
                select_list(arr, size, &choice1, &one);
                delete (&choice1);
                arr[one] = choice1;
                break;
            case 15:
                select_list(arr, size, &choice1, &one);
                arr = split_list(arr, &size, choice1);
                print_heads(arr, size);
                break;
            case 16:
                select_list(arr, size, &choice1, &one);
                select_list(arr, size, &choice2, &two);
                arr = join_list(arr, &size, one, two);
                arr[one] = choice1;
                print_heads(arr, size);
                break;
            case 17:
                select_list(arr, size, &choice1, &one);
                write_info(choice1);
                break;
            case 18:
                read_info(&first);
                arr[0] = first;
                one = 0;
                break;
            case 19:
                for (int i = 0; i < size; i++) free_list(&arr[i]);
                arr = realloc(arr, sizeof(Node*));
                size = 1;
                break;
        }
    } while (option != 0);

    for (int i = 0; i < size; i++) free_list(&arr[i]);
    arr = realloc(arr, sizeof(Node*));
    size = 1;
    return 0;
}