#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_PROD 10
#define MAX_NOMBRE 30

// Declaraciones de funciones
void ingresarDatos(char nombres[][MAX_NOMBRE], float precios[], int n);
float calcularTotal(float precios[], int n);
float calcularPromedio(float precios[], int n);
int productoMasCaro(float precios[], int n);
int productoMasBarato(float precios[], int n);
void mostrarDetalles(char nombres[][MAX_NOMBRE], float precios[], int n);
void buscarProducto(char nombres[][MAX_NOMBRE], float precios[], int n, char nombreBuscado[]);

#endif
