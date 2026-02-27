#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Include your custom header files using quotes
#include "filesManagement/filesManager.h"
#include "calculations/calculator.h"

int main() {
    int unidadesPulidas;
    FILE *registroPulidas;

    // 1. Manage the file
    registroPulidas = getFile();

    // 2. Do the calculations
    float precioPorUnidad = getPrecioUnidad();
    unidadesPulidas = contarUnidadesPulidas(registroPulidas);
    insertarImporteTotal(registroPulidas, unidadesPulidas, precioPorUnidad);

    // 3. Cleanup
    fclose(registroPulidas);

    printf("\nPresione cualquier tecla para cerrar...");
    getch();

    return 0;
}
