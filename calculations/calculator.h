#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include <stdio.h>

// Function declarations
float getPrecioUnidad();
int encontrarUnidadesEnLinea(char *linea);
int contarUnidadesPulidas(FILE* registroPulidas);
void insertarImporteTotal(FILE* registroPulidas, int unidadesPulidas, float precioUnidad);

#endif
