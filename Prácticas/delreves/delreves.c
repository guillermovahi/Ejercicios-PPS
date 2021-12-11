#include <stdio.h>
#include <string.h>

void invert_and_print_line(char *line);

int main(int argc, char *argv[])
{
	if(argc == 2 && strcmp(argv[0],"delreves") == 0 && strcmp(argv[1],"-h") == 0)
	{
		printf("delreves: Uso: delreves [ fichero... ]\n");
		printf("delreves: Invierte el contenido de las líneas de los ficheros (o de la entrada).");
		return 1;
	}

	int i;

	i = 0;
	while(++i < argc)
	{
		if (i != 1)
			printf("\n");
		
		FILE *my_file = fopen(argv[i], "r");
		if (my_file == NULL)
		{
			printf("El fichero \"%s\" no puede ser leido.", argv[i]);
			return 1;
		}

		char line[2048];

		while(fgets(line,2048,my_file))
			invert_and_print_line(line);

		fclose(my_file);
	}
	
	return 0;
}

void invert_and_print_line(char *line)
{
	int i, j, aux;
	
	i = 0;
	while((line[i] != '\n') && (line[i] != '\0'))
		i++;
	aux = i;
	
	j = -1;
	while(j < --i)
		printf("%c",line[i]);	
	
	if(line[aux] != '\0')
		printf("\n");
}