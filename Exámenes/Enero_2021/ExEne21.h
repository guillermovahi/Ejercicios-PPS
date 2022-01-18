#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lineas
{
	char *linea;
	struct lineas *siguiente;
} lista_lineas;

lista_lineas *cargar_f1(FILE *f);
void unir_f1_f2(FILE *f, const char *sep, lista_lineas *lptr);
void liberar(lista_lineas *lptr);

/*	CARGAR LÍNEAS DEL PRIMER FICHERO EN MEMORIA DINÁMICA
	SE VALORARÁ ESPECÍFICAMENTE LA CLARIDAD Y ESTRUCTURA DEL CÓDIGO */
lista_lineas *cargar_f1(FILE *f)
{	
	char line[2049];
	int length;
	lista_lineas *head = NULL;
	lista_lineas *aux = NULL;
	lista_lineas *nuevo = NULL;

	while(fgets(line, 2049, f) != NULL)
	{
		length = strlen(line);
		if(line[length - 1] == '\n')
			line[length - 1] = 0;

		nuevo = (lista_lineas *) malloc(sizeof(lista_lineas));
		if(nuevo == NULL)
		{
			fprintf(stderr, "ERROR: No se pudo asignar memoria dinámica\n");
			return NULL;
		}
		nuevo->linea = strdup(line);
		if(nuevo->linea == NULL)
		{
			fprintf(stderr, "ERROR: No se pudo asignar memoria dinámica\n");
			return NULL;
		}
		nuevo->siguiente = NULL;

		if(head == NULL)
		{
			head = nuevo;
			aux = head;
		}
		else
		{
			aux->siguiente = nuevo;
			aux = aux->siguiente;
		}
	}

	return head;
}

/*	UNIR LÍNEAS DEL SEGUNDO FICHERO E IMPRIMIR */
void unir_f1_f2(FILE *f, const char *sep, lista_lineas *lptr)
{
	char linea[2049];
	lista_lineas *aux;

	aux = lptr;

	while(fgets(linea, 2049, f) && aux != NULL)
	{
		fprintf(stdout, "%s%s%s", aux->linea, sep, linea);
		aux = aux->siguiente;
	}

	if(feof(f) && aux != NULL)
		fprintf(stderr, "STOP: Fichero 2 tiene menos lineas\n");
	
	if(!feof(f) && aux == NULL)
		fprintf(stderr, "STOP: Fichero 1 tiene menos lineas\n");
}

/*	LIBERAR MEMORIA DINÁMICA */
void liberar(lista_lineas *lptr)
{
	lista_lineas *aux = lptr;
	lista_lineas *aux2;

	while(aux != NULL)
	{
		aux2 = aux;
		aux = aux->siguiente;
		free(aux2->linea);
		free(aux2);
	}
}