# Clase 1: Selection sort

Diremos que un algoritmo es correcto si, y solo si cumple los siguientes requisitos:

- Termina en una cantidad finita de pasos.
- Cumple su proposito.

Al deemostrar la correctitud de un algoritmo, lo haremos a través de inducción, verificando que si ordena hasta n, entonces el caso con n+1 deberia ser correcto a su vez.

## Selection sort
Este algoritmo toma una lista l de n elementos y los ordena entregando una lista l' ordenada. Su procedimiento consiste en buscar el menor elemento de l, ingresarlo a l' y eliminarlo de l.

```pseudocode
input: L
output: L' (ordenado)

SelectionSort(A):
    1 Define L' vacía
    2 Busca el menor dato de L
    3 Saca x de L y lo ingresa al final de L'
    4 Si quedan valores en L, vuelve a la linea 2.
```

## Complejidad
Asumiremos que L tiene n elementos, osea que la magnitud de L es n.

Hay 2 formas de calcularlo:
1. Implicita: Saber que L recorre los n elementos para buscar el menor. Luego repite la búsqueda n veces, entonces nos quedaría que el algoritmo lee los datos n² veces.
2. Explicita: Al buscar el menor elemento, inicialmente debemos leer n datos. Luego n-1, n-2... hasta 1 elemento. El tiempo total es la suma de la lectura de cada pasada de los datos, siendo correspondiente a n(n+1)/2. 
Luego al expandir y aplicando análisis de complejidad algorítmica quedaria 1/2 n² + 1/2 n, ignorando constantes y considerando mayor tamaño quedaria n².

