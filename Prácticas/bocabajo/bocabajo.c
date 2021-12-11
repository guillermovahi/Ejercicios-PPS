#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void invert_and_print_line(int n_lines, char *file, int n_file, int files);

int main(int argc, char *argv[])
{
	if(argc == 2 && strcmp(argv[0],"bocabajo") == 0 && strcmp(argv[1],"-h") == 0)
	{
		printf("bocabajo: Uso: bocabajo [ fichero... ]\n");
		printf("bocabajo: Invierte el orden de las lineas de los ficheros (o de la entrada).");
		return 1;
	}
	
	char line[2048];
	int i, n_lines;
	
	

	i = 0;
	while(++i < argc)
	{	
		FILE *my_file = fopen(argv[i], "r");
		if (my_file == NULL)
		{
			printf("El fichero \"%s\" no puede ser leido.", argv[i]);
			return 1;
		}

		n_lines = 0;
		while(fgets(line,2048,my_file))
			n_lines++;

		fclose(my_file);
		invert_and_print_line(n_lines, argv[i], i, argc - 1);
	}
	
	return 0;
}

void invert_and_print_line(int n_lines, char *file, int n_file, int files)
{
	int i, j, aux;
	aux = n_lines;
	
	char **array;
	char line[2048];

	FILE *my_file = fopen(file, "r");

	array = (char **) malloc(sizeof(char *) * n_lines);

	while(fgets(line,2048,my_file))
		array[--n_lines] = strdup(line);
	
	for(i = 0; i < aux; i++)
	{
		if( i == 0)
			printf("%s\n", array[i]);
		else
		{
			j = -1;
			while(array[i][++j] != '\n')
				printf("%c", array[i][j]);
			if (i+1 != aux || n_file < files)
				printf("\n");
		}
	}

	fclose(my_file);
}