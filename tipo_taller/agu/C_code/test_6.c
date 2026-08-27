# include <stdio.h>

void change_value(char letter)
 
{

}

int main () {


    int value = 10;
    int *puntero = &value;

    printf("%p", puntero); // dirección en memoria
    printf("\n%d", *puntero); // valor del puntero
    
    int **ptp_1 = &puntero;

    printf("\n%p", ptp_1);
    return 0;
}