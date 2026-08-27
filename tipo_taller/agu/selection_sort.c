# include <stdio.h>


void selectionSort(int arr[], int n) 
{
    for (int i = 1; i < n;i++) 
    {
        int min = arr[i];
        int j;
        for (j = 1; j < n;j++) 
        {
            if (arr[j] < min) 
            {
                min = arr[j];
            }
        }
        int aux = arr[i];
        arr[i] = arr[min];
        arr[min] = aux;
        }
}

int main () 
{
    int arr[] = {10,15,1,12,65,70,13,99,100,15};
    int n = 10;
    printf("Antes: ");
    elem_array(arr, n);
    selectionSort(arr, n);
    printf("Todavía:  ");
    elem_array(arr, n);
    return 0;
}
