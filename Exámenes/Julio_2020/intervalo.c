#include <stdio.h>
#include <stdlib.h>
#define MAX_LONG 2048

int main(int argc, char *argv[])
{
	FILE *fichero = stdin;
	int inicio, fin;
	char linea[MAX_LONG];
	int n_linea = 1;

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

	/* SALTAR HASTA INICIO O EOF */
	while(fgets(linea, MAX_LONG -1, fichero) != NULL)
	{
		if (n_linea >= inicio && n_linea <= fin)
			fprintf(stdout, "%s", linea);
		n_linea++;
	}

	fclose(fichero);
	exit(0);
}