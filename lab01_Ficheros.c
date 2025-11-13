/*****************************
* Pontificia Universidad Javeriana
* Autor: David Tobar Artunduaga
* Materia: Sistemas Operativos
* Tema: Sistema de ficheros
* Descripción:
*   Programa que lee el contenido de un fichero llamado "readme.txt"
*   utilizando las funciones fopen() y fgets(). Muestra su contenido
*   línea por línea por pantalla.
********************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *nombreFichero = "readme.txt";  // Puntero que almacena el nombre del archivo a leer.
    FILE *fp = fopen(nombreFichero, "r"); // Abre el archivo en modo lectura ("r").

    // Si no se puede abrir el archivo, muestra un mensaje de error y termina.
    if (fp == NULL) {
        printf("Error: no se puede abrir el fichero.\n");
        return 1;
    }

    // Si el archivo se abre correctamente, inicia la lectura.
    printf("\nLectura de fichero readme.txt\n");

    const unsigned LARGO_MAX_LINEA = 256;  // Máximo número de bytes a leer por línea.
    char buffer[LARGO_MAX_LINEA];          // Arreglo donde se almacenará cada línea leída.

    // Lee línea por línea hasta llegar al final del archivo o al límite de tamaño definido.
    while (fgets(buffer, LARGO_MAX_LINEA, fp))
        printf("%s", buffer);  // Imprime cada línea en pantalla.

    // Cierra el archivo al finalizar la lectura.
    fclose(fp);

    return 0;
}
        /*Conclusión:
        El programa demuestra el uso básico de manejo de archivos en lenguaje C,
        empleando las funciones estándar fopen(), fgets() y fclose().
         A través de este ejemplo, se observa cómo abrir un fichero en modo lectura,
        verificar su correcta apertura, leer su contenido línea por línea y mostrarlo en pantalla.
        Este tipo de práctica es fundamental para comprender la gestión de flujos de entrada/salida en C, 
        así como el control de errores al trabajar con archivos en sistemas operativos.*/