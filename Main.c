#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main() {
    char nombres[MAX_PROD][MAX_NOMBRE];
    float precios[MAX_PROD];
    int n;
    char respuesta[5];
    char nombreBuscado[MAX_NOMBRE];

    do {
        printf("Cuantos productos desea ingresar (maximo 10)? ");
        scanf("%d", &n);

        if (n <= 0) {
            printf("Error: ingrese un numero mayor que 0.\n");
        } else if (n > MAX_PROD) {
            printf("Error: no puede ingresar mas de 10 productos.\n");
        }
    } while (n <= 0 || n > MAX_PROD);

    ingresarDatos(nombres, precios, n);

    mostrarDetalles(nombres, precios, n);

    printf("\nDesea buscar un producto? (si/no): ");
    scanf("%s", respuesta);

    if (strcmp(respuesta, "si") == 0 || strcmp(respuesta, "SI") == 0) {
        printf("Ingrese el nombre del producto a buscar: ");
        scanf("%s", nombreBuscado);
        buscarProducto(nombres, precios, n, nombreBuscado);
    } else {
        printf("Saliendo del programa...\n");
    }

    return 0;
}
