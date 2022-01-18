#include "exjul21.h"

/* CARGA LÍNEAS DEL FICHERO F Y ACTUALIZA LA LISTA Y CONTADORES EN PTR */

void cargar(FILE *f, lista_contadores *ptr)
{
	char linea[2049];
	int error_memoria = 0;
	lista_lineas *nuevo = NULL;
	lista_lineas *ultimo = NULL;

	while(!error_memoria && fgets(linea, 2049, f) != NULL)
	{
		nuevo = (lista_lineas *) malloc(sizeof(lista_lineas));
		if(nuevo == NULL)
			error_memoria = 1;

		if(error_memoria != 1)
		{
			nuevo->linea = strdup(linea);
			if (nuevo->linea == NULL)
				error_memoria = 1;
		}

		if(error_memoria != 1)
		{
			if((strlen(linea) % 2) == 0) 
				ptr->contador_par++;
			else
				ptr->contador_impar++;

			if(ultimo == NULL)
				ptr->lista = nuevo;
			else
				ultimo->siguiente = nuevo;
			ultimo = nuevo;
		}
	}
	if(error_memoria)
	{
		fprintf(stderr, "ERROR: No se puede asignar memoria dinámica\n");
		exit(71);
	}
}