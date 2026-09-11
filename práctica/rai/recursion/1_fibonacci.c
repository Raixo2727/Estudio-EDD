#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n) {
    if (n==0) {
        return 0;
    } else if (n==1) {
        return 1;
    }

    return fibonacci(n-1) + fibonacci(n-2);
}

int main () {
    int n = 3;

    printf("Fibonacci con: %d elementos \n", n);
    int resultado = fibonacci(n);
    printf("Resultado: %d\n", resultado);

    return 0;
}