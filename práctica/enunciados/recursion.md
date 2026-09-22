# Recursion

Estos ejercicios ayudarán a practicar recursión y soltar la mano.

## Ejercicio 1
Crear la secuencia de fibonacci:
f(0) = 0
f(1) = 1

f(n) = f(n-1) + f(n-2)

```c

/*
 * Retorna el n-ésimo número de Fibonacci de forma recursiva.
 * Asume n >= 0.
 */
int fibonacci(int n) {
    // 1. Casos base: ¿cuáles son los valores directos que no requieren sumar nada?
    
    // 2. Paso recursivo: invocar la función con subproblemas más chicos y sumar.
}

```

## Ejercicio 2
Ver si una palabra es palindromo.


```c
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_palindrome(char *s, int start, int end) {
    // 1. Caso base de éxito: ¿qué pasa si start >= end?
    
    // 2. Caso base de fallo: ¿qué pasa si las letras s[start] y s[end] son distintas?
    
    // 3. Paso recursivo: ¿cómo avanzas los índices para revisar el resto de la palabra?
}
```

## Ejercicio 3
Ver si una clave numerica esta dentro de un arreglo de enteros.

Target puede ser un numero cualquiera y el arreglo apunta a numeros cualquiera.

```c
bool find_element(int *arr, int size, int target)
```

## Ejercicio 4
En un centro de distribución, los sensores de una cinta transportadora registran el estado de una fila de paquetes en un arreglo de enteros. Cada paquete con código negativo (valor < 0) representa una carga dañada que debe enviarse a control de calidad. Necesitas saber cuántos paquetes dañados hay en total en la fila.


```c
#include <stdio.h>

/*
 * Retorna la cantidad de elementos menores a 0 en el arreglo.
 */
int count_damaged_packages(int *arr, int size) {
    // Escribe tu solución aquí
}
```

## Ejercicio 5
En un sistema embebido con memoria muy limitada, recibes un arreglo de enteros que representa lecturas de un sensor tomadas en orden cronológico inverso. Debes dar vuelta el arreglo modificando sus elementos directamente en la memoria original (in-place), sin crear un segundo arreglo.

```c
#include <stdio.h>


void reverse_array(int *arr, int start, int end) {
    // Tu código aquí
}
```

## Ejercicio 6
En una base de datos optimizada, los registros están estrictamente ordenados de menor a mayor. Para encontrar un dato rápidamente en $O(\log n)$, en lugar de revisar uno a uno, comparas con el elemento del medio. Si no coincide, descartas la mitad completa donde es imposible que esté y continúas buscando en la mitad restante.

```c
/*
 * Retorna el índice de target si existe, o -1 si no se encuentra.
 * left: índice inicial del rango de búsqueda.
 * right: índice final del rango de búsqueda.
 */
int binary_search(int *arr, int left, int right, int target) {
    // Escribe tu solución aquí
}
```

