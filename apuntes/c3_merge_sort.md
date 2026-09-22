# Clase 3: Merge sort
## Merge

Pensemos en un array tal que tenga 2 partes conectadas. La primera parte denominada p1 esta ordenada con unos 8 elementos y la segunda, denominada p2, tendrá 4 elementos más. P1 esta completamente ordenada en si misma, igualmente lo hará p2,  sin embargo el array completo no esta ordenado ya que hay elementos x e p2 tal que x debe estar antes que algunos elementos pertenecientees a p1.


| **Valor** | 8 | 20 | 29 | 40 | 50 | 60 | 70 | 82 | 15 | 32 | 41 | 65 |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **Índice** | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |

## Merge
Este se encargará de analizar la lista que le hayan dado y empezará a ordenarla. A partir de 2 conjuntos de números, que pueden pertenecer al mismo array, los empieza a ordenar para tener un orden común.

Su gracia es comparar el primer elemento de cada parte del array e ingresarlos al resultado final. Hay que fijarse que pasa cuando no quedan elementos en alguno de los arrays.

## Merge sort

En cambio lo que hará **merge sort** será separar el array original y usar la estrategia dividir para conquistar. Dividirá el array en sub arrays llamandose a si mismo recursivamente. Cuando llegue a lo menor posible, llamará a **merge** para re armar todas las sub listas para ordenadas y volver a la lista original pero ordenada.

El algoritmo tiene 2 partes principales:
1. Particionar el array original.
2. Ordenar las listas ordenadas de las particiones.

## Complejidad de merge
La comparación entre los 2 datos toma simplemente O(1) cada uno, esto lo haremos n veces siendo n el tamaño del array, por ende quedaría O(n)

Una vez acabada alguna de las listas, colocar los elementos restantes también toma O(n).

Merge usa O(n). Esto siendo out place. Si es in place cuesta O(n²) por tener que desplazar los datos del mismo array.

## Complejidad de merge sort

Ahora esta combina la división de los arreglos y merge.
1. La división es log 2 (n). Esto correspondería a cuantas divisiones deberia realizar para llegar a los elementos atómicos. 
2. Para hacer merge en cada piso cuesta n, ya que siempre trabajará n casos independiente de la cantidad de divisiones.

Por ell cuesta =(n log n)