/*****************************
* Pontificia Universidad Javeriana
* Autor: David Tobar Artunduaga
* Materia: Sistemas Operativos
* Tema: Sistema de ficheros
* Descripción:
*   Programa que recibe un nombre de directorio y muestra por pantalla:
*     - Los nombres de los ficheros y subdirectorios que contiene.
*     - El modo (permisos) del archivo.
*     - Si el propietario tiene permiso de lectura.
*     - Si es un directorio o un fichero regular.
*     - Si el fichero fue modificado en los últimos 10 días,
*       su fecha de modificación y su valor en segundos (epoch time).
********************************/

#include <dirent.h>     // Para manejar directorios (opendir, readdir, closedir)
#include <stdio.h>      // Para printf, fgets, etc.
#include <string.h>     // Para funciones de cadena como strcpy, strcat, strlen
#include <time.h>       // Para manejar fechas y tiempos (time, ctime)
#include <fcntl.h>      // Para control de archivos (opcional en este programa)
#include <unistd.h>     // Para funciones del sistema POSIX
#include <sys/stat.h>   // Para obtener los atributos de archivos (stat)
#include <sys/types.h>  // Tipos de datos usados en sys/stat.h y dirent.h

int main() {
    int er;                        // Variable para almacenar el resultado de stat()
    char nomdir[100];              // Nombre del directorio ingresado por el usuario
    char nomfich[100];             // Nombre completo del fichero dentro del directorio
    char resp[30];                 // Variable sin uso funcional (puede eliminarse)
    struct stat atr;               // Estructura que almacena los atributos del archivo
    DIR *d;                        // Puntero al directorio abierto
    struct dirent *rd1;            // Puntero a la estructura que representa una entrada del directorio
    time_t fecha;                  // Variable para guardar el tiempo actual

    printf("Nombre directorio\n");
    fgets(nomdir, sizeof(nomdir), stdin);  // Leer el nombre del directorio desde el teclado

    /* Quitar el salto de línea final que deja fgets */
    nomdir[strlen(nomdir) - 1] = '\0';

    /* Obtener la fecha y hora actuales */
    fecha = time(&fecha);

    /* Intentar abrir el directorio */
    if ((d = opendir(nomdir)) == NULL) {
        printf("No existe ese directorio \n");
        return -1; // Termina el programa si no se puede abrir el directorio
    } else {
        /* Leer cada entrada (archivo o subdirectorio) dentro del directorio */
        while ((rd1 = readdir(d)) != NULL) {

            /* Ignorar las entradas "." y ".." (directorios especiales) */
            if ((strcmp(rd1->d_name, ".") != 0) && (strcmp(rd1->d_name, "..") != 0)) {

                /* Construir la ruta completa del archivo */
                strcpy(nomfich, nomdir);
                strcat(nomfich, "/");
                strcat(nomfich, rd1->d_name);

                /* Mostrar el nombre completo del fichero */
                printf("fichero :%s:", nomfich);

                /* Obtener los atributos del fichero */
                er = stat(nomfich, &atr);

                /* Mostrar el modo (permisos) del archivo en formato octal */
                printf("modo :%#o:", atr.st_mode);

                /* Verificar si el propietario tiene permiso de lectura */
                if ((atr.st_mode & 0400) != 0)
                    printf(" permiso R para propietario\n");
                else
                    printf(" No permiso R para propietario\n");

                /* Verificar si es un directorio */
                if (S_ISDIR(atr.st_mode))
                    printf(" Es un directorio \n");

                /* Verificar si es un archivo regular */
                if (S_ISREG(atr.st_mode))

                    /* Comprobar si fue modificado en los últimos 10 días */
                    if ((fecha - 10 * 24 * 60 * 60) < atr.st_mtime) {
                        printf("FICHERO: %s: fecha de modificación %s, en segundos %ld\n",
                               nomfich,
                               ctime(&atr.st_mtime),   // Fecha legible de modificación
                               atr.st_mtime);          // Fecha en formato numérico (epoch time)
                    }
            }
        }

        /* Cerrar el directorio después de procesar todas sus entradas */
        closedir(d);
    }

    return 0; // Fin del programa
}

/* 
Conclusión:
Este programa permite explorar un directorio y obtener información detallada de los archivos que contiene. 
Usando funciones del sistema como opendir(), readdir() y stat(), se puede identificar si una entrada es un 
archivo o un subdirectorio, consultar sus permisos, y verificar si ha sido modificada recientemente. 
Además, muestra cómo trabajar con fechas en C mediante la librería <time.h>. 
En general, el código ayuda a entender cómo los sistemas operativos almacenan y gestionan los metadatos 
de los archivos, reforzando conceptos de permisos, estructuras de datos y control de acceso en el sistema de ficheros.
*/
