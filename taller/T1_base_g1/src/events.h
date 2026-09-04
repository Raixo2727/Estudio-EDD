#pragma once
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int *right_size
);

void rebuild(
    int *array, 
    int *left, 
    int left_size, 
    int pivot1, 
    int *middle, 
    int middle_size, 
    int pivot2, 
    int *right, 
    int right_size
);

void quicksort(int *array, int size);
