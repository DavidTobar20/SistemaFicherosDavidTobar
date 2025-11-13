# Explicación del archivo `readme.txt`

Este archivo (`readme.txt`) fue creado para probar y demostrar el funcionamiento de los programas desarrollados en los laboratorios de **Sistemas Operativos**, específicamente aquellos relacionados con el manejo de **ficheros** en lenguaje C.

## Propósito
El objetivo principal del `readme.txt` es servir como archivo de entrada para el programa del **Laboratorio 1 (lab01_Ficheros.c)**, el cual utiliza funciones estándar de manejo de archivos en C (`fopen()`, `fgets()`, `fclose()`) para leer y mostrar el contenido de un fichero línea por línea.

## Contenido de ejemplo
El archivo `readme.txt` contiene texto simple que puede ser leído por el programa, por ejemplo:

## Funcionamiento con el programa
1. El programa abre el archivo `readme.txt` en modo lectura (`"r"`).
2. Verifica si el archivo existe y puede abrirse correctamente.
3. Si la apertura es exitosa, lee su contenido línea por línea utilizando `fgets()`.
4. Cada línea leída se muestra por pantalla mediante `printf()`.
5. Finalmente, se cierra el archivo con `fclose()` para liberar los recursos.

## Ejemplo de salida esperada
Al ejecutar el programa `lab01_Ficheros.c`, la salida en la terminal será similar a:


## Conclusión
El archivo `readme.txt` permite comprobar el correcto funcionamiento de las funciones de lectura de ficheros en C, siendo una base para entender cómo los programas pueden interactuar con archivos de texto dentro de un sistema operativo.
