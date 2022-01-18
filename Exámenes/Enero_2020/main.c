#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* FUNCIÓN APARTADO d) */

char *strdup2(const char *s)
{
	char *cadena;
	
	/* CÓDIGO */
	int i = 0;
	while(s[i] != '\0')
		i++;
	cadena = malloc(i * sizeof(char) + 1);
	if (cadena != NULL)
	{
		cadena[i] = 0;
		while(--i != 0)
			cadena[i] = s[i];
	}

	return cadena;
}

/* FUNCIÓN APARTADOS c) y d) */
/* Se recomienda usar char *fgets(char *str, int n, FILE *stream) */

int contar_lineas(FILE *file)
{
	char *segunda_linea;
	/* 	DECLARACIÓN DE VARIABLES NECESARIAS */
	int n_lineas = 0;
	char buffer[81];

	/* CÓDIGO */
	while(fgets(buffer, 81, file) != EOF)
	{
		n_lineas++;
		if (n_lineas == 2)
		{
			segunda_linea = strdup2(buffer);
			if(segunda_linea != NULL)
			{
				fprintf(stdout, "%s\n", segunda_linea);
				free(segunda_linea);
			}
		}
	}
	return n_lineas;

}

int main(int argc, char *argv[])
{
	/* DECLARACIÓN DE VARIABLES NECESARIAS */
	FILE *fichero;
	int n_lineas;

	/* CÓDIGO CORRESPONDIENTE AL APARTADO a) */
	if (argc != 2)
	{
		fprintf(stderr, "Error: el programa espera un argumento de entrada correspondiente al fichero a tratar.\n");
		exit(1);
	}


	/* CÓDIGO CORRESPONDIENTE AL APARTADO b) */
	fichero = fopen(argv[1], "r");

	if(fichero == NULL)
	{
		fprintf(stderr, "Error: el fichero \"%s\" no existe o no es legible", argv[1]);
		exit(2);
	}

	/* CÓDIGO CORRESPONDIENTE AL APARTADO c) (llamada y salida) */
	n_lineas = contar_lineas(fichero);
	fprintf(stdout, "El número de líneas es %d\n", n_lineas);

	/* CÓDIGO CORRESPONDIENTE AL APARTADO e) */
	fclose(fichero);
	exit(0);
}