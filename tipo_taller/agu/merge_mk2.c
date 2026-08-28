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
int minim(int arr[], int n) 
{
    int min = 0;
    for (int i = 0; i < n;i++) 
    {
        if (arr[i] < arr[min]) 
        {
        min = i;
        }
    }
    return min;
}

void merge(int arr_a[], int lo, int mid, int hi) 
{
    int i = 0;
    int j = mid;

    while (i < mid && j < hi) 
    {
        if (arr_a[i] < arr_a[j]) 
        {
            printf("%d\n", arr_a[i]);
            i++;
        }
        else 
        {
            printf("%d\n", arr_a[j]);
            j++;
        }
    }
    return;
}
// ====================================
int main()
{
    int arr_a[8] = {9, 12, 15, 65, 23, 43, 45, 54};
    int n = 4;

    printf("Antes: \n");
    print_array(arr_a, n);
    printf("Todavia: \n");
    merge(arr_a, 0, n, 7);
    print_array(arr_a, n);
    // printf("Todavía:  ");
    // print_array(arr_c, n);
    return 0;
}
// ====================================


