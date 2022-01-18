#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LONG 2048

int main(int argc, char *argv[])
{
	FILE *fichero = stdin;
	int inicio, fin;
	char **lineas;
	char linea[MAX_LONG];
	int n_linea = 1, i = -1;

	if (argc < 3 || argc > 4)
	{
		fprintf(stderr, "uso: ./intervalo INICIO FIN [FICHERO] (INICIO y FIN enteros positivos)");
		exit(1);
	}
	
	inicio = atoi(argv[1]);
	fin = atoi(argv[2]);
	if (inicio < 1 || fin < 1)
	{
		fprintf(stderr, "uso: ./intervalo INICIO FIN [FICHERO] (INICIO y FIN enteros positivos)");
		exit(2);
	}

	if(argc == 4)
	{
		fichero = fopen(argv[3], "r");
		if (fichero == NULL)
		{
			fprintf(stderr, "./intervalo: error al abrir el fichero '%s'", argv[5]);
			exit(3);
		}
	}

	if(fin < inicio)
	{
		fclose(fichero);
		exit(0);
	}

	lineas = (char **) malloc((fin - inicio + 1) * sizeof(char *));
	if(lineas == NULL)
	{
		fclose(fichero);
		fprintf(stderr, "./inverso: no se ha podido solicitar memoria\n");
		exit(8);
	}

	/* SALTAR HASTA INICIO O EOF */
	while(fgets(linea, MAX_LONG -1, fichero) != NULL)
	{
		if (n_linea >= inicio && n_linea <= fin)
			lineas[++i] = strdup(linea);
		n_linea++;	
	}

	while(i >= 0)
	{
		fprintf(stdout, "%s", lineas[i]);
		free(lineas[i--]);
	}
	free(lineas);
	fclose(fichero);
	exit(0);
}