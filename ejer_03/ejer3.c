#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	FILE *archivo;
	char caracteres[1000];
	float max_value;
	float min_value;
	float value;

	archivo = fopen(argv[1], "r");
	if (archivo == NULL)
        exit(1);
    else
    {   
		fgets(caracteres, 100, archivo);
		value = atof(caracteres);
		max_value = value;
		min_value = value;
        while (feof(archivo) == 0)    
 	    {
            value = atof(fgets(caracteres, 100, archivo));
			if (value > max_value)
				max_value = value;
			else if(value < min_value)
				min_value = value;	
 	    }
    }
    fclose(archivo); 
	printf("MIN VALUE: %10.2f\nMAX VALUE: %10.2f\n", min_value, max_value);
	return 0;
}