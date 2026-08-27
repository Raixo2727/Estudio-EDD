# include <stdio.h>
void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        // i recorre el arreglo
        int key = arr[i];
        int j = i - 1;

        // j recorre todos los elementos anteriores respecto al indice i
        // y los ordena
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        
    }


}


void elem_array(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%d | ", arr[i]); 
    }
    printf("\n");
}

int main () 
{
    int arr[] = {10,15,1,12,65,70,13,99,100,15};
    int n = 10;
    printf("Antes: ");
    elem_array(arr, n);
    insertion_sort(arr, n);
    printf("Todavía:  ");
    elem_array(arr, n);
    return 0;
}
