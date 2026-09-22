# Clase 2: Insertion sort

Algoritmos como selection sort que no necesitan espacio adicional para ordenarse se llaman *in place*.

## Insertion sort

Selection es caro ya que ordena elementos que ya estan ordenados. Insertar elementos sería una forma de hacer más barata que revisar cada elemento.

Toma elementos de un array y lo coloca en una lista ordenada. No lee la lista completa, en vez, colocará el elemento temporal en la posición adecuada de acuerdo a parámetros de desigualdades/igualdades. Al ingresar un elemento nuevo recorrerá de acuerdo a su valor y cuando encuentre el espacio, insertará el elemento en la lista previamente ordenada.

```pseudocode
input : Secuencia de datos A
output: Nueva secuencia de datos B, ordenada

InsertionSort (A):
1    Definir secuencia B, inicialmente vacía
2    Tomar el primer dato x de A
3    Sacar x de A
4    Insertar x en B de manera que B quede ordenada
5    Si quedan datos en A, volver a la línea 2
    return B
```

A diferencia de **selection sort**, esta no agrega los elementos al final sino que coloca el elemento en una lista ya ordenada y la ubica donde corresponde.

## Complejidad
Ahora con el elemento nuevo tenemos que considerar 2 casos:
- El elemento es mayor que todos, entonces se agrega al final.
- De lo contrario se encuentra la posición leyendo los datos antes y luego se desplaza los elementos mayores que el por 1 posición, siendo una lectura de n veces.

(Esto es leyendo de derecha a izquierda)

Con esto entonces tendríamos O(n). Osea que la inserción es de complejidad O(n). 

Pero a diferencia de selection, este tiene casos:
- Peor caso: La lista esta al inverso que como deberia ir el orden. Debemos leer cada elemento y desplazar a cada uno de ellos 1 posición, osea que seria o(n²).

## Inversiones
Diremos asi a los cambios entre números, osea los cambios posibles que puedan haber para ordenar una lista. Esto lo podemos ver usando combinatoria. 

Regresando a insertion, ordena solamente si existe una inversión entre elementos j y j-1.

En el mejor caso, el arreglo esta ordenado y hay 0 inversiones, siendo O(n). 

En el peor cada elemento tiene una inversión equivalente a n-1, siendo desde n hasta 1. Su suma sería n(n+1)/2, resultante de O(n²).

---

Ahora para el promedio, consideraremos la cantidad de combinaciones de inversiones posibles, siendo n! casos posibles. I.e: si fueran 3 elementos, tendriamos 6 formas de tener el orden: 0, 1, 2 y 3 inversiones, siendo respectivamente 1 de 0, 2 de 1, 2 de 2 y 1 de 3, 6 casos en total.

Luego evaluamos cuantas inversiones hay en 1 pareja, siendo estos de la permutación de casos posibles. Esta corresponde siemper a n(n-1)/2 por las combinaciones que hay con cada numero. Esto teniendo en cuenta que son las inversiones de la pareja, sumadas dan ese valor. 

Como tenemos n!/2 parejas, multiplicamos con n(n-1)/2 y luego lo promediamos con las n! casos, resultando en n².

## Conclusión
Si A es un algoritmo de ordenación que corrige una inversión por intercambio, entonces su mejor tiempo es de O(n²).


