#include "calculator.h"
#include <stdio.h>

#define CHAR_SEPARADOR ':'

float getPrecioUnidad() {
    float precio;
    printf("\nIngrese el precio por unidad: ");

    while (scanf("%f", &precio) != 1 || precio < 0) {
        while(getchar() != '\n');
        printf("Entrada invalida. Ingrese un precio valido: ");
    }
    while (getchar() != '\n');
    return precio;
}

int encontrarUnidadesEnLinea (char *linea){
    int numeroEncontrado = 0;
    //buscar el separador de nombre[separador]canidad
    while(*linea != CHAR_SEPARADOR && *linea != '\0'){
        linea++;
    }

    //si hay una linea mal formada se detiene
    if (*linea == '\0') {
        return 0;
    }

    //saltar caracteres entre el [separador] y la cantidad
    do {
        linea++;
    } while(*linea == ' ' && *linea != '\0');

    //extraigo la cantidad
    while(*linea != '\0' && *linea != '\n' && *linea >= '0' && *linea <= '9'){
        numeroEncontrado = numeroEncontrado*10 + (*linea - '0');
        linea++;
    }
    return numeroEncontrado;
}

int contarUnidadesPulidas(FILE* registroPulidas){
    char linea[256];
    int unidadesTotal = 0;
    int unidadesLeidas = 0;

    // We make sure we are reading from the beginning of the file
    rewind(registroPulidas);

    while(fgets(linea, sizeof(linea), registroPulidas)){
        unidadesLeidas = encontrarUnidadesEnLinea(linea);
        unidadesTotal += unidadesLeidas;
    }
    return unidadesTotal;
}

void insertarImporteTotal(FILE* registroPulidas, int unidadesPulidas, float precioUnidad){
    float sueldo = unidadesPulidas * precioUnidad;
    char mensajeFinalDeLinea[256];

    snprintf(mensajeFinalDeLinea, sizeof(mensajeFinalDeLinea),"\nEl saldo final del mes es: $%.2f \nCon una tarifa por unidad de $%.2f\n", sueldo, precioUnidad);
    fputs(mensajeFinalDeLinea, registroPulidas);

    printf("\nEl sueldo registrado en el archivo fue: $%.2f", sueldo);
    printf("\nUnidades: %d, Costo por unidad: $%.2f\n", unidadesPulidas, precioUnidad);
}
