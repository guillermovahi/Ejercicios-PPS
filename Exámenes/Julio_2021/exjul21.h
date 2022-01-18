#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lineas
{
	char *linea;
	struct lineas *siguiente;
}	lista_lineas;

typedef struct contadores
{
	lista_lineas *lista;
	int contador_par;
	int contador_impar;
}	lista_contadores;

void cargar(FILE *f, lista_contadores *ptr);
void imprimir(lista_contadores *ptr);