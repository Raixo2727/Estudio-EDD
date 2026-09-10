// Merge MK3 (in process )
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
// review conditions and indexs problems
void merge(int arr[], int lo, int mid, int hi) 
{
    int * arrtemp = malloc((hi - lo + 1) * sizeof(int));
    int i = lo;
    int j = mid;
    int k = 0;

    while (i > 10) 
    {
        
    }
}

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