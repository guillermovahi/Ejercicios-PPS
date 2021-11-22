#include "pilavector.h"
#include <stdlib.h>
#include <stdio.h>
//Me declaro la pila ?¿?¿?¿
tpv pila;


/*
 * Inicializar todos los contenedores en la pila a 0 y la cima a -1 (indica vacía)
 */

void init(void) // ?
{
	pila.top = -1;
}

/*
 * Restaurar la pila al estado inicial
 */

void vaciar(void)
{
	while(pila.top != -1)
		pop();

}

/*
 * Comprobar si está llena. Devuelve 1 si lo está y 0 en caso contrario
 */

int llena(void)
{
	return (pila.top == MAXPILA - 1);
}

/*
 * Comprobar si está vacía. Devuelve 1 si lo está y 0 en caso contrario
 */

int vacia(void)
{
	return (pila.top == -1);
}

/*
 * Operación push: apila item
 * Devuelve 0 si apila y -1 en caso contrario
 */

int push(tdata item)
{
	if (llena())
        return -1;

	pila.datos[pila.top+1] = item;
    (pila.top)++;
    return 0;

}

/*
 * Operación pop: devuelve el contenido en la cima de la pila
 * En la cima hay un item especial que marca vacía
 */

tdata pop(void)
{
	tdata item;
	
	item = pila.datos[pila.top--];

	return item;
}

/*
 * Mostrar el contenido de la pila
 */

void display(void)
{
	int index = pila.top;
	printf("Contenido pila:\n");
	while(index != -1)
	{
		printf("\tID: %d\n", pila.datos[index].id);
		printf("\tMatricula: %s\n", pila.datos[index].matricula);
		printf("\tAlumno: %s\n", pila.datos[index].nombre);
		printf("\tMail: %s\n", pila.datos[index].mail);
		printf("\tNota: %f\n",pila.datos[index].nota);
		index--;
	}
	
}