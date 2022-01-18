#include "exjul21.h"

void liberar(lista_lineas *lptr);

/* LIBERAR MEMORIA DINÁMICA */
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

/* IMPRIMIR LAS LÍNEAS QUE CORRESPONDAN Y LIBERAR MEMORIA DINÁMICA */
void imprimir(lista_contadores *ptr)
{
	lista_lineas *aux;

	aux = ptr->lista;

	if(ptr->contador_par != ptr->contador_impar)
	{
		while(aux != NULL)
		{
			if(ptr->contador_par > ptr->contador_impar)
			{
				if(strlen(aux->linea) % 2 == 0)
					fprintf(stdout, "%s", aux->linea);
			}
			else
			{
				if(strlen(aux->linea) % 2 != 0)
					fprintf(stdout, "%s", aux->linea);
			}
			aux = aux->siguiente;
		}
	}
	liberar(ptr->lista);	
}