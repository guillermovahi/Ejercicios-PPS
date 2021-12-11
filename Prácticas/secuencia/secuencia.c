#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_OUTPUT 100


int main(int argc, char *argv[])
{
	if(argc == 2 && strcmp(argv[0],"secuencia") == 0 && strcmp(argv[1],"-h") == 0)
	{
		printf("secuencia: Uso: secuencia [ hasta [ desde [ paso ]]]\n");
		printf("secuencia: Genera la secuencia de numeros en el intervalo y paso indicados.");
		return 1;
	}
	
	if (argc > 4)
	{
		printf("secuencia: Error(EX_USAGE), uso incorrecto del mandato. \"Success\"\n");
		printf("secuencia+ El parametro \"hasta\" no es numero real valido");
		return 1;
	}

	float	hasta = 10;
	float 	desde = 1;
	float 	paso = 1;	
	int i;

	if (argc == 2)
		hasta = atof(argv[1]);
	else if (argc == 3)
	{
		hasta = atof(argv[1]);
		desde = atof(argv[2]);
	}
	else if (argc == 4)
	{
		hasta = atof(argv[1]);
		desde = atof(argv[2]);
		paso = atof(argv[3]);

		if ((hasta > 0 && paso < 0) || (hasta < 0 && paso > 0))
		{
			printf("secuencia: Error(EX_USAGE), uso incorrecto del mandato. \"Success\"\n");
			printf("secuencia+ El signo de \"paso\" no permite recorrer el intervalo en el sentido \"desde\"");
			return 1;
		}
	}
	
	i = -1;
	if (hasta > 0)
	{
		while(desde <= hasta && ++i < MAX_OUTPUT)
		{
			printf("\t%g\n",desde);
			desde += paso;
		}
	}
	else
	{
		while(desde >= hasta && ++i < MAX_OUTPUT)
		{
			printf("\t%g\n",desde);
			desde += paso;
		}
	}
	if (i == MAX_OUTPUT)
	{
		printf("secuencia: Error(EX_NOPERM), permiso denegado. \"Success\"\n");
		printf("secuencia+ Se intento superar el limite de salida.");
		return 1;
	}

	return 0;
}