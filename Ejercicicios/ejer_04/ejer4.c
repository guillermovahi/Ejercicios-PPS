#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	//Control de errores
	if (argc != 2)
	{
		fprintf(stderr,"ERROR\n");
		return 1;
	}

	FILE *archivo;
	char linea[80];
	char linea_aux[80];

	archivo = fopen(argv[1], "r");
	if(archivo == NULL)
	{
		fprintf(stderr,"ERROR\n");
		return 1;
	}
	else
	{
		while(fgets(linea, 81, archivo) != NULL)
		{
			/* if(fgets(linea_aux, 81, archivo) != NULL)
			{
				fputs(linea, stdout);
				if (strcmp(linea, "\n") != 0)
					fprintf(stdout,"\n");
				fputs(linea_aux, stdout);
				if (strcmp(linea_aux, "\n") != 0)
					fprintf(stdout,"\n");
			}
			else
			{ */
				fputs(linea, stdout);
				if (strcmp(linea, "\n") != 0)
					fprintf(stdout,"\n");
		}
		fclose(archivo);
	}
	return 0;
}