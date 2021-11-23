#include <stdio.h>

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

	archivo = fopen(argv[1], "r");
	if(archivo == NULL)
	{
		fprintf(stderr,"ERROR\n");
		return 1;
	}
	else
	{
		while(feof(archivo) == 0)
		{
			fgets(linea, 81, archivo);
			fputs(linea, stdout);
			fprintf(stdout,"\n");
		}
		fclose(archivo);
	}
	return 0;
}