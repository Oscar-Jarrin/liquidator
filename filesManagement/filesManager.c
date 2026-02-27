#include "filesManager.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#ifdef _WIN32
    #include <direct.h>
    #define makeDir(path) _mkdir(path)
#endif

int esUnMesValido(char* mes){
    return (
        strcmp(mes, "enero") == 0 ||
        strcmp(mes, "febrero") == 0 ||
        strcmp(mes, "marzo") == 0 ||
        strcmp(mes, "abril") == 0 ||
        strcmp(mes, "mayo") == 0||
        strcmp(mes, "junio") == 0||
        strcmp(mes, "julio") == 0||
        strcmp (mes, "agosto") == 0||
        strcmp(mes, "septiembre") == 0||
        strcmp(mes, "octubre") == 0 ||
        strcmp(mes, "noviembre") == 0 ||
        strcmp(mes, "diciembre") == 0
    );
}

FILE* getFile(){
    char extension[5] = ".txt";
    char carpeta[17] = "RegistrosMeses/";
    char mes[10];
    char direccionCompleta[34];

    printf("Ingrese el mes que quiere liquidar: ");
    scanf("%9s", mes);

    for (int i=0; mes[i] != '\0'; i++){
        mes[i] = tolower(mes[i]);
    }

    while(!esUnMesValido(mes)){
        printf("El mes ingresado no es valido. \nReingrese el mes que quiere liquidar: ");
        scanf("%9s", mes);
    }

    snprintf(direccionCompleta, sizeof(direccionCompleta), "%s%s%s",carpeta, mes, extension);

    if (makeDir(carpeta) == -1) {
        if (errno != EEXIST) {
            printf("Creating folder...\n");
        }
    }

    FILE *registroPulidas = fopen(direccionCompleta, "a+");
    if(registroPulidas == NULL){
        printf("no se pudo cargar el archivo\n");
        exit(1);
    }

    printf("Se cargo el archivo: %s ", direccionCompleta);
    return registroPulidas;
}
