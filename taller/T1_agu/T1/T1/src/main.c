#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "events.h"
#include "libedd/AltTwoPartition.h"

/* Retorna true si ambos strings son iguales */
static bool string_equals(char *string1, char *string2) {
  return !strcmp(string1, string2);
}

static bool check_arguments(int argc, char **argv) {
  if (argc != 3) {
    printf("Modo de uso: %s INPUT OUTPUT\n", argv[0]);
    printf("Donde:\n");
    printf("\tINPUT es la ruta del archivo de input\n");
    printf("\tOUTPUT es la ruta del archivo de output\n");
    exit(1);
  }
  return true;
}

static int* read_array(FILE *input_file, int size) {
  int *array = calloc(size, sizeof(int));
  for (int i = 0; i < size; i++) {
    fscanf(input_file, "%d", &array[i]);
  }
  return array;
}

static void print_array(FILE *output_file, int *array, int size) {
  for (int i = 0; i < size; i++) {
    fprintf(output_file, " %d", array[i]);
  }
  fprintf(output_file, "\n");
}

int main(int argc, char **argv) {
  check_arguments(argc, argv);

  FILE *input_file = fopen(argv[1], "r");
  FILE *output_file = fopen(argv[2], "w");

  if (!input_file || !output_file) {
    printf("Error al abrir los archivos.\n");
    return 1;
  }

  int E;
  int result = fscanf(input_file, "%d", &E);
  if (result != 1) {
    printf("Error leyendo el numero de eventos\n");
    return 1;
  }

  char command[32];
  for (int i = 0; i < E; i++) {
    result = fscanf(input_file, "%s", command);
    if (result != 1) {
      printf("Error leyendo el evento\n");
      return 1;
    }

    if (string_equals(command, "TWOPARTITION")) {
      int size;
      fscanf(input_file, "%d", &size);
      
      int *array = read_array(input_file, size);
      
      int pivot1, pivot2;
      int left_size, middle_size, right_size;
      
      int *left = malloc(size * sizeof(int));
      int *middle = malloc(size * sizeof(int));
      int *right = malloc(size * sizeof(int));

      TwoPartition(array, size, &pivot1, &pivot2, left, &left_size, middle, &middle_size, right, &right_size);
      
      fprintf(output_file, "Resultado de la ejecucion de TwoPartition:\n");
      fprintf(output_file, "Pivot1: %d\n", pivot1);
      fprintf(output_file, "Pivot2: %d\n", pivot2);
      fprintf(output_file, "Left:");
      print_array(output_file, left, left_size);
      
      fprintf(output_file, "Middle:");
      print_array(output_file, middle, middle_size);
      
      fprintf(output_file, "Right:");
      print_array(output_file, right, right_size);
      
      // Liberamos memoria
      free(array);
      free(left);
      free(middle);
      free(right);

    } else if (string_equals(command, "REBUILD")) {
      int left_size, middle_size, right_size, pivot1, pivot2;
      
      fscanf(input_file, "%d", &left_size);
      int *left = read_array(input_file, left_size);

      fscanf(input_file, "%d", &pivot1);

      fscanf(input_file, "%d", &middle_size);
      int *middle = read_array(input_file, middle_size);

      fscanf(input_file, "%d", &pivot2);

      fscanf(input_file, "%d", &right_size);
      int *right = read_array(input_file, right_size);

      int total_size = left_size + middle_size + right_size + 2;
      int *array = calloc(total_size, sizeof(int));
      
      //función a implementar Parte 2.1
      rebuild(array, left, left_size, pivot1, middle, middle_size, pivot2, right, right_size);

      fprintf(output_file, "Resultado de la ejecucion de Rebuild:\n");
      for (int j = 0; j < total_size; j++) {
        fprintf(output_file, "%d%s", array[j], (j == total_size - 1) ? "" : " ");
      }
      fprintf(output_file, "\n");

      free(array);
      free(left);
      free(middle);
      free(right);

    } else if (string_equals(command, "TWOQUICKSORT")) {
      int size;
      fscanf(input_file, "%d", &size);
      
      int *array = read_array(input_file, size);


      //función a implementar Parte 2.2
      quicksort(array, size);

      fprintf(output_file, "Arreglo ordenado con TwoQuickSort:\n");
      for (int j = 0; j < size; j++) {
        fprintf(output_file, "%d%s", array[j], (j == size - 1) ? "" : " ");
      }
      fprintf(output_file, "\n");

      free(array);
    }
  }

  fclose(input_file);
  fclose(output_file);

  return 0;
}
