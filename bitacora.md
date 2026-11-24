# Bitácora — Obligatorio 2

**Integrantes:** Nombre Apellido (Nº estudiante), Nombre Apellido (Nº estudiante)

> **Instrucciones** (borrar esta sección antes de entregar): agregar una entrada por
> cada día trabajado, indicando la fecha y quién trabajó (un integrante o "En conjunto").
> Registrar el proceso real: ideas exploradas, decisiones y su justificación, partes de
> implementaciones, bugs encontrados y cómo se corrigieron, resultados de pruebas y dudas
> abiertas. Si se usó IA ese día, indicar herramienta, consulta y qué se hizo con la
> respuesta. Una bitácora escrita íntegramente el día de la entrega implica pérdida de puntos.

## 2026-11-24 — Martina González 
- Voy a implementar el ejercicio 9, luego de la explicación de clase
- Terminé de implementarla, la voy a probar

## 2026-11-16 — Martina González 
- Pensé el ejercicio 9, lo que queremos maximizar son los likes, pero la limitante en este ejercicio es no perder, así que pensé en poder un contador que sea golesAnotados-golesRecibidos y nunca dejar que sea negativo. Supongo que en las llamadas a la matriz memo, van a ser entre la opción de bailar y no bailar, esa opción se va a dar siempre y cuando el contador no quede negativo. 
Lo arranqué a hacer y no entiendo porque se necesitaría una matriz y no un array, voy a arrancar a hacerlo con el array hasta darme cuenta
Codifiqué para si el anterior baila o hacer que no baile para maximizar likes, pero me doy cuenta que puede pasar que inicialmente no baile y no le metan gol para despues dejarse meter gol por más likes y eso ahora no lo estoy tomando en cuenta.
Se ve en el ejemplo 5: "Los dos últimos tiros valen mucho, pero en esas rondas A erra. Para bailar en los dos, A tiene que llegar a la ronda 4 con dos goles de ventaja. Con tres goles a favor, el Pato puede gastar uno solo antes."

## 2026-11-15 — Martina González duda sacar lo de liberar memoria
- Completé una parte de justificacion.md de los ejercicios 6,7 y 8

## 2026-11-15 — Martina González duda sacar lo de liberar memoria
- Pensé el ejercicio 8 mi idea es hacer una array de 6 dimensiones, una por el peso otra por el producto y otra por las categorias, también me basé en el orden que dice el ejercicio para pensar los 6 fors. Lo voy pensando a medida que lo voy haciendo, pero voy siguendo la misma lógica que en la clase, solo que con 6 dimensiones, el maximo valor entre usarlo y no usarlo, si puedo elegir entre usarlo o no. Ya lo terminé, me pasó segmentation fault, pero fue cambiar una coondición en el for, después, anduvieron las pruebas

## 2026-11-15 — Martina González 
- Pensé el ejercicio 6 mi idea es hacer un array desde 0 hasta 1000, en cada posición la cantidad de veces que aparece cada número. Al principio pensé en un array de bool desde 0 hasta 1000 que en cada posición diga si está una cantidad par o impar de veces pero no es necesario. Una vez que esté cargado el array, agarro el mayor impar y después de menor a mayor le voy agregando el resto. 
- Le pregunté a char como hacer para pasar un int a un string, y es con to_string(). Compilé y el test me dio un número enorme porque en el if me olvidé de poner diferente de 0. Corriendo las pruebas de 100.in.txt me di cuenta que no estoy tienendo en cuenta los casos que son mayores que 2


## 2026-11-15 — Martina González DUDA HAY UQE PONER EL CHAT?
- Estoy haciendo una corrida a mano para ver en qué está fallando el ejericicio, vi lo de size of que me pareció que podía estar ahí el error y le pregunté a chatgpt (https://chatgpt.com/share/6afa2fd9-a604-83e9-a209-b7c0193ffa5e) si eso se podía usar en c y me dijo que sí pero que en punteros no da el resultado que yo quiero que de porque hace el largo del puntero. Entocnes, voy a cambiar eso y ver si me da bien. Ahora el resultado me dio menos de lo que tenía que dar, así que supongo que me falta contar casos, sigo con la corrida a mano. En la corrida a mano me di cuenta que me estaban faltando contar casos porque solo los estoy comparando con el primero del array, pero eso no quiere decir que mas adelante no haya remontadas épicas. Enotnces, voy a poner otro contador para que se fije si más adelante hay. Ahora hice el caso de prueba y me dio un número más grande del que me tenía que dar

## 2026-11-04 — Martina González
- Tenemos que hacer el obligatorio en un repositorio git entonces copié y pegué lo que ya había hecho y puse los tests en el repositorio
- Me dio mal voy a poner cout para ver el orden y que casos estoy contando de más, con cout me mostraron muchos 0 aunque el caso de prueba no tenía 0.


## 2026-11-03 — Martina González
- Volví a leer la letra del ejercicio 7, habíamos hablado en clase de merge sort, sumando la cantidad de remontadas cuando corresponde. Copié y pegué el código de merge sort de las diapositivas, y lo modifiqué. No lo probé porque no encontré las pruebas. 