#include "events.h"
#include "libedd/AltTwoPartition.h"

// Taller 1 completado
void TwoPartition(
    int *array, 
    int size, 
    int *pivot1, 
    int *pivot2, 
    int *left, 
    int *left_size, 
    int *middle, 
    int *middle_size, 
    int *right, 
    int *right_size) 
{

    // TODO: PREGUNTA 1

    if (array[0] < array[size - 1]) {
        *pivot1 = array[0];
        *pivot2 = array[size - 1];
    } else {
        *pivot1 = array[size - 1];
        *pivot2 = array[0];
    }

    *left_size = 0;
    *middle_size = 0;
    *right_size = 0;

    for (int i=1; i<size-1; i++) {
        if (array[i] < *pivot1) {
            left[*left_size] = array[i];
            (*left_size)++;
        } else if (array[i] >= *pivot1 && array[i] <= *pivot2) {
            middle[*middle_size] = array[i];
            (*middle_size)++;
        } else {
            right[*right_size] = array[i];
            (*right_size)++;
        }
    }
}

void rebuild(
    int *array, 
    int *left, int left_size, int pivot1, 
    int *middle, int middle_size, int pivot2, 
    int *right, int right_size
) 
{
    //TODO: PREGUNTA 2.1
    int pos_array = 0;
    
    for (int i = 0; i < left_size; i++) {
        array[pos_array] = left[i];
        pos_array++;
    }

    array[pos_array] = pivot1;
    pos_array++;

    for (int i = 0; i < middle_size; i++) {
        array[pos_array] = middle[i];
        pos_array++;
    }

    array[pos_array] = pivot2;
    pos_array++;

    for (int i = 0; i < right_size; i++) {
        array[pos_array] = right[i];
        pos_array++;
    }
    

}

void quicksort(int *array, int size)
{    
    //TODO: PREGUNTA 2.2 

    if (size <= 1) {
        return;
    }

    int* left = calloc(size, sizeof(int));
    int* middle = calloc(size, sizeof(int));
    int* right = calloc(size, sizeof(int));

    int pivot1;
    int pivot2;

    int left_size;
    int middle_size;
    int right_size;

    TwoPartition(array, size, &pivot1, &pivot2, left, &left_size, middle, &middle_size, right, &right_size);
    quicksort(left, left_size);
    quicksort(middle, middle_size);
    quicksort(right, right_size);

    rebuild(array, left, left_size, pivot1, middle, middle_size, pivot2, right, right_size);
    free(left);
    free(middle);
    free(right);
}
