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

void merge(int arr[], int lo, int mid, int hi) 
{
    int i = lo;
    int j = mid;
    int k = 0;

    while (i <= mid && j <= hi) 
    {   
        if (arr[i] < arr[j]) 
        {
            // printf("%d\n", arr[i]);
            i++;
        }
        else 
        {
            // printf("%d\n", arr[j]);
            // cambiamos posiciones INCORRECTO
            int aux = arr[i];
            arr[i] = arr[j]; 
            arr[j] = aux;
            j++;
        }
    }
    // printf("%d - %d \n", i,j);

    while (i < mid) 
    {
        // printf("%d\n", arr[i]);
        i++;
    }
    while (j < hi) 
    {
        // printf("%d\n", arr[j]);
        j++;
    }
    return;
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


