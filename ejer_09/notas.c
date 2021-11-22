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
char *get_name(char *line);
char *get_surname(char *line);
void insertar(lista_notas **ptr, char *name, char *surname, int grade);
void mostrar_lista(lista_notas *ptr);
void free_lista(lista_notas *ptr);

int main(int argc, char *argv[])
{	
	char line[MaxLinea+1];
	char *name;
	char *surname;
	lista_notas *mi_lista = NULL;
	int i, blank, grade;
	FILE *archivo = fopen(argv[1], "r");

	while(fgets(line, MaxLinea, archivo)) //recorrer linea fich
	{
		grade = get_grade(line);		
		if (grade < 5) //Insertar en la lista
		{
			name = get_name(line);
			surname = get_surname(line);
			insertar(&mi_lista, name, surname, grade);
		}
	}
	
	fclose(archivo);
	archivo = fopen(argv[1], "r");
	
	while(fgets(line, MaxLinea, archivo)) //recorrer linea fich
	{
		grade = get_grade(line);		
		if (grade > 4) //Insertar en la lista
		{
			name = get_name(line);
			surname = get_surname(line);
			insertar(&mi_lista, name, surname, grade);
		}
	}
	
	
	mostrar_lista(mi_lista);
	free_lista(mi_lista);

	//system("leaks a.out");
	return 0;
}


void insertar(lista_notas **ptr, char *name, char *surname, int grade)
{
	lista_notas *p1, *p2;

	p1 = *ptr;
	if(p1 == NULL)
	{
		p1 = malloc(sizeof(lista_notas));//y si usamos calloc ¿qué cambia?
		if (p1 == NULL)
			exit(71);
		if (p1 != NULL)
		{
			p1->nombre = name;
			p1->apellido = surname;
			p1->nota = grade;
			p1->siguiente = NULL;
			*ptr = p1;
		}
	}
	else
	{
		while(p1->siguiente != NULL)//recorrer la lista hasta el último
			p1 = p1->siguiente;
		p2 = malloc(sizeof(lista_notas));//y si usamos calloc ¿qué cambia?
		if (p2 == NULL)
			exit(71);
		if(p2 != NULL)
		{
			p2->nombre = name;
			p2->apellido = surname;
			p2->nota = grade;
			p2->siguiente = NULL;
			p1->siguiente = p2;
		}
	}
}

void mostrar_lista(lista_notas *ptr)
{
	while(ptr != NULL)
	{
		printf("%s ",ptr->nombre);
		printf("%s ",ptr->apellido);
		printf("%d\n",ptr->nota);
		ptr = ptr->siguiente;
	}
/*	printf("\n");*/
}

void free_lista(lista_notas *ptr)
{
	lista_notas *aux = ptr;
	lista_notas *aux2;

	while(aux != NULL)
	{
		aux2 = aux;
		aux = aux->siguiente;
		free(aux2->nombre);
		free(aux2->apellido);
		free(aux2);	
	}
}

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
	int i;
	char *name = malloc(51);
	if (name == NULL)
		exit(71);

	i = 0;
	
	while(line[i] != ' ')
		name[i] = line[i++];
		
	name[i] = 0;

	return name;
}

char *get_surname(char *line)
{
	int i, j;
	char *surname = malloc(101);
	if (surname == NULL)
		exit(71);
	
	i = 0;
	j = 0;

	while(line[i] != ' ')
		i++;

	while(line[++i] != ' ')
		surname[j++] = line[i];
	
	surname[j] = 0;

	return surname;
}

