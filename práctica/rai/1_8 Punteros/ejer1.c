#include <stdlib.h>
#include <stdio.h>

typedef struct cuenta {
    int id;
    float saldo;
} Cuenta;

void depositar(Cuenta *cuenta, float monto) {
    cuenta -> saldo += monto;
}

int main() {
    Cuenta cuenta;

    cuenta.id = 1;
    cuenta.saldo = 100.00;

    depositar(&cuenta, 100.00);
    printf("El nuevo saldo es: %f\n", cuenta.saldo);
    return 0;
}