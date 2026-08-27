#include <stdio.h>

char concat(char x, char y){
    return x + y;
}

int main(int argc, char const *argv[])
{

    
    int cat_ramirez;
    cat_ramirez = 22;

    printf("Hi brother \n"); // el printf no incluye el /n !!

    if (cat_ramirez > 21) {
    printf("Hola ramirez\n");
    }

    int edad_ramirez = 19;
    int* direccion = &edad_ramirez;

    printf("%i\n", edad_ramirez);
    printf("%i\n", *direccion);
    printf("%p\n", direccion);
    printf("%p\n", &edad_ramirez);
    return 0;
}


// compilar: gcc test_1.c

// ./test_1.exe args

