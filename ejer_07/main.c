#include "parser.h"

int main(int argc, char *argv[])
{
	if (argc < 2)
		parser(stdin);
	else if(argc == 2)
	{
		FILE *archivo = fopen(argv[1], "r");
		parser(archivo);
	}
	
	return 0;	
}