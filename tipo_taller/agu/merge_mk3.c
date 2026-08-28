// Merge MK2 falló
// ====================================
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// ====================================
void print_array(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%d | ", arr[i]); 
    }
    printf("\n");
}
// ====================================


// ====================================
int main()
{
    int arr_a[8] = {9, 12, 15, 65, 23, 43, 45, 54};
    int n = 4;

    printf("Antes: \n");
    print_array(arr_a, 8);
    merge(arr_a, 0, n, 7);
    printf("Despues: \n");
    print_array(arr_a, 8);
    // printf("Todavía:  ");
    // print_array(arr_c, n);
    return 0;
}
// ====================================