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

void merge(int arr_a[], int n, int arr_b[], int m) 
{
    int i = 0;
    int j = 0;
    while (i < n && j < m) 
    {
        // printf("entrando al while: i: %d- j: %d\n", i, j);
        if (arr_a[i] < arr_b[j]) 
        {
            printf("%d\n", arr_a[i]);
            i++;
        }
        else 
        {
            printf("%d\n", arr_b[j]);
            j++;
        }
    }
    int l, p;
    if (i < j)
    {
        l = i;
        p = n;
    }
    else
    {
        l = j;
        p = m;
    }
    // printf("%d - %d\n", l, m);
    for (l; l < p; l++) 
    {
        printf("%d\n",arr_a[l]);
    }
    return;
}
// ====================================
int main()
{
    int arr_a[4] = {9, 12, 15, 65};
    int arr_b[4] = {23, 43, 45, 54};
    int n = 4;
    int f = minim(arr_b, 4);

    printf("El indice del valor minimo es: %d\n", f);

    printf("Antes: \n");
    print_array(arr_a, n);
    print_array(arr_b, n);
    
    merge(arr_a, n, arr_b, n);
    // printf("Todavía:  ");
    // print_array(arr_c, n);
    return 0;
}
// ====================================



