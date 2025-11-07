#include <stdio.h>
#include <string.h>
#include "funciones.h"

void ingresarDatos(char nombres[][MAX_NOMBRE], float precios[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nIngrese el nombre del producto %d: ", i + 1);
        scanf("%s", nombres[i]);

        do {
            printf("Ingrese el precio del producto %d: ", i + 1);
            scanf("%f", &precios[i]);
            if (precios[i] <= 0) {
                printf("Error: el precio debe ser mayor que 0.\n");
            }
        } while (precios[i] <= 0);
    }
}

float calcularTotal(float precios[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += precios[i];
    }
    return total;
}

float calcularPromedio(float precios[], int n) {
    return calcularTotal(precios, n) / n;
}

int productoMasCaro(float precios[], int n) {
    int indice = 0;
    for (int i = 1; i < n; i++) {
        if (precios[i] > precios[indice]) {
            indice = i;
        }
    }
    return indice;
}

int productoMasBarato(float precios[], int n) {
    int indice = 0;
    for (int i = 1; i < n; i++) {
        if (precios[i] < precios[indice]) {
            indice = i;
        }
    }
    return indice;
}

void mostrarDetalles(char nombres[][MAX_NOMBRE], float precios[], int n) {
    printf("\n--- Detalles de los productos ---\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s - Precio: %.2f\n", i + 1, nombres[i], precios[i]);
    }

    float total = calcularTotal(precios, n);
    float promedio = calcularPromedio(precios, n);
    int caro = productoMasCaro(precios, n);
    int barato = productoMasBarato(precios, n);

    printf("\nPrecio total del inventario: %.2f\n", total);
    printf("Precio promedio: %.2f\n", promedio);
    printf("Producto mas caro: %s (%.2f)\n", nombres[caro], precios[caro]);
    printf("Producto mas barato: %s (%.2f)\n", nombres[barato], precios[barato]);
}

void buscarProducto(char nombres[][MAX_NOMBRE], float precios[], int n, char nombreBuscado[]) {
    int encontrado = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(nombres[i], nombreBuscado) == 0) {
            printf("El precio de %s es: %.2f\n", nombres[i], precios[i]);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Producto no encontrado.\n");
    }
}
