# Justificación de órdenes — Obligatorio 2


## Ejercicio 6
- Justificación: tiene O(n), temporal, siendo n la cantidad de placas porque hace un for hasta n, e hice dos for de 1 hasta 1000 en que es orden constante en peor caso. 
- Tiene orden espacial constante porque placas es de tamaño 1000 

## Ejercicio 7
- Justificación: tiene O(nlogn) temporal siendo n la cantidad de corredores, porque es el orden del merge sort, y la suma de resultado utiliza el índice l que no vuelve para atrás, como máximo recorre el largo del array1, entonces, no cambia el orden del merge
Tiene orden espacial O(n) porque llegada es de largo n

## Ejercicio 8

- Justificación: tiene orden O(N*W*L1*L2*L3*L3) temporal porque hay 6 fors, entonces, el orden se multiplica y lo mismo con el orden espacial por las matrices de 6 dimensiones con esos largos

## Ejercicio 9
- Tiene O(K^2) temporal, siendo k la cantidad de formas, porque peor caso llena todo memo, que tiene dimension 3, pero el tercero es de largo 2, constante, no depende de k.
Tiene orden k^2 espacial por la matriz de k^2 multiplicado por 2 que es constante

## Ejercicio 10
- Sin restricciones de órdenes.

