#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxLinea 154
//Tamaño máximo linea = 50 (nombre) + 100 (apellido) + 2 (nota máx 10) 
	// + 2 espacios + caracter nulo? = 155

typedef struct notas{
	char *nombre;
	char *apellido;
	int nota;
	struct notas *siguiente;
} lista_notas;

int get_grade(char *line);

int main(int argc, char *argv[])
{	
	char line[MaxLinea+1];
	char *name;
	lista_notas *mi_lista = NULL;
	int i, blank, num;
	FILE *archivo = fopen(argv[1], "r");



	while(fgets(line, MaxLinea, archivo)) //recorrer linea fich
	{
		num = get_grade(line);
		name = get_name(line);
		printf("%s",name);
/* 
		if (num < 5) //Insertar en la lista
		{

		} */
	}


	return 0;
}

/* void insertar(lista_notas **ptr, char elemento)
{
	lista_notas *p1, *p2;

	p1 = *ptr;
	if(p1 == NULL)
	{
		p1 = malloc(sizeof(lista_notas));//y si usamos calloc ¿qué cambia?
		if (p1 != NULL)
		{
			p1->dato = elemento;
			p1->enlace = NULL;
			*ptr = p1;
		}
	}
	else
	{
		while(p1->enlace != NULL)//recorrer la lista hasta el último
			p1 = p1->enlace;
		p2 = malloc(sizeof(lista_notas));//y si usamos calloc ¿qué cambia?
		if(p2 != NULL)
		{
			p2->dato = elemento;
			p2->enlace = NULL;
			p1->enlace = p2;
		}
	}
}
 */

int get_grade(char *line)
{
	int i, blank, num;

	i = 0;
	blank = 0;
	while(line[i] != '\0')
	{
		if (blank == 2) //sacar la nota
		{
			num = atoi(&line[i]);
			blank++;
		}
		else if(line[i] == ' ')
			blank++;
		i++;	
	}
	return num;
}

char *get_name(char *line)
{
	char name[50+1];
	int i;

	i = 0;
	
	while(line[i] != ' ')
	{
		strcat(name[i], line[i]);
		i++;	
	}
	name[i] = 0;

	return name;
}
