# include <stdio.h>


void selectionSort(int arr[], int n) 
{
    for (int i = 0; i < n;i++) 
    {
        int min = i;
        int j;
        for (j = i+1; j < n;j++) 
        {
            if (arr[j] < arr[min]) 
            {
                min = j;
            }
        }
        // cambiamos posiciones
        int aux = arr[i];
        arr[i] = arr[min]; 
        arr[min] = aux;
        }
}

void print_array(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%d | ", arr[i]); 
    }
    printf("\n");
}

int main () 
{
    int arr[] = {10,15,1,12,65,70,13,99,100,14};
    int n = 10;
    // printf("%d",arr[0]);
    printf("Antes: ");
    print_array(arr, n);
    selectionSort(arr, n);
    printf("Todavía:  ");
    print_array(arr, n);
    return 0;
}
