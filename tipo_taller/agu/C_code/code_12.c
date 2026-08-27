# include <stdio.h>


// ========================================================
// PRINTING ARRAY
int elem_array(int arr[], int size) 
{
    int i;
    for (i=0; i < size; i++) 
    {
        printf("%d | ", arr[i]);
    }
    return 0;
}
// ========================================================

// ========================================================
// Main CODE
int main(int argc, char const *argv[])
{
    int arr_1[] = {7, 5, 11, 22, 4, 23};
    int size = sizeof(arr_1) / sizeof(arr_1[0]);
    
    int min, aux, j;

    // ###########################
    // inicio select
    for (int i = 0; i < size-1; i++) 
    {
        min = arr_1[i];
        for (j = i; j < size; j++) 
        {
            if (arr_1[j] < arr_1[min]) 
            {
                min = j;
            }
        }
        aux = arr_1[i];
        arr_1[i] = arr_1[min];
        arr_1[min] = aux;
    }
    // fin select
    // ###########################
    // final print
    elem_array(arr_1, size);
    return 0;
}
// ========================================================