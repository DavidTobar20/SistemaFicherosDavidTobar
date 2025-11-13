/*****************************
* Pontificia Universidad Javeriana
* Autor: David Tobar Artunduaga
* Materia: Sistemas Operativos
* Tema: Sistema de ficheros
* Descripción:
*   Programa que lee desde teclado el nombre de un directorio y muestra
*   en pantalla el nombre y el tamaño (en bytes) de todos los ficheros
*   regulares contenidos en dicho directorio.
********************************/

#include <sys/types.h>   // Tipos de datos del sistema (usados en stat, dirent)
#include <sys/stat.h>    // Para obtener información sobre archivos (struct stat)
#include <sys/mman.h>    
#include <fcntl.h>       // Control de archivos (open, O_RDONLY, etc.)
#include <stdio.h>       // Funciones estándar de entrada/salida (printf, fgets)
#include <unistd.h>      // Funciones POSIX (close, etc.)
#include <stdlib.h>      // Funciones generales (exit, malloc, etc.)
#include <string.h>      // Manejo de cadenas (strlen, strcat, strcpy)
#include <dirent.h>      // Manejo de directorios (opendir, readdir, closedir)

int main() {
    DIR *d;                        // Puntero al directorio que se va a abrir
    char nomdir[90], nomfich[90];  // Buffers para el nombre del directorio y del fichero
    struct stat datos;             // Estructura para guardar información del archivo
    struct dirent *direc;          // Estructura que representa cada entrada del directorio

    // Solicitar al usuario el nombre del directorio
    printf("Introduzca el Nombre de un Directorio: ");
    fgets(nomdir, sizeof(nomdir), stdin);   // Leer el nombre del directorio desde teclado

    // Eliminar el salto de línea '\n' al final de la cadena
    nomdir[strlen(nomdir) - 1] = '\0';

    // Intentar abrir el directorio especificado
    if ((d = opendir(nomdir)) == NULL) {
        printf("El directorio no existe\n");
        return -1;   // Termina el programa si no se puede abrir
    }

    // Leer todas las entradas (archivos y subdirectorios) dentro del directorio
    while ((direc = readdir(d)) != NULL) {

        // Construir la ruta completa del fichero (directorio + "/" + nombre de archivo)
        strcpy(nomfich, nomdir);
        strcat(nomfich, "/");
        strcat(nomfich, direc->d_name);

        // Obtener la información del archivo usando stat()
        stat(nomfich, &datos);

        // Verificar si la entrada es un archivo regular (no directorio)
        if (S_ISREG(datos.st_mode))
            // Mostrar el nombre del archivo y su tamaño en bytes
            printf("Nombre: %s\t| Tamaño: %ld bytes\n", direc->d_name, datos.st_size);
    } /* Fin del while: se procesan todas las entradas del directorio */

    // Cerrar el directorio una vez finalizado el recorrido
    closedir(d);

    return 0; // Fin del programa
}
/* 
Conclusión:
Este programa muestra cómo usar funciones del sistema en C para trabajar con directorios. 
Permite ingresar un nombre de carpeta y listar todos los archivos regulares dentro de ella, 
mostrando su nombre y tamaño en bytes. Gracias a funciones como opendir(), readdir() y stat(), 
se entiende mejor cómo los sistemas operativos manejan los ficheros y su información. 
Además, sirve para practicar la manipulación de rutas, estructuras y control de errores al acceder al sistema de archivos.
*/
