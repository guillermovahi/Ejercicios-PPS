#include "exjul21.h"

int main(int argc, char const *argv[])
{
	FILE *entrada = stdin;
	lista_contadores *lc = NULL;

	/* COMPROBAR ERROR DE ARGUMENTOS */
	if(argc > 2 )
	{
		fprintf(stderr, "ERROR: numero de argumentos incorrecto\n");
		exit(64);
	}
	
	/* INICIALIZACIÓN DE LISTA CONTADORES */
	lc = (lista_contadores *) malloc(sizeof(lista_contadores));
	if(lc == NULL)
	{
		fprintf(stderr, "ERROR: No se puede asignar memoria dinamica\n");
		exit(71);
	}
	lc->contador_impar = 0;
	lc->contador_par = 0;
	lc->lista = NULL;

	/* DETERMINAR SI HAY UN FICHERO COMO ARGUMENTO O ES STDIN*/
	if(argc == 2)
	{
		entrada = fopen(argv[1], "r");
		if(entrada == NULL)
		{
			fprintf(stderr, "ERROR: No se ha podido abrir el archivo %s\n", argv[1]);
			exit(66);
		}
		cargar(entrada, lc);
		fclose(entrada);
	}
	else
		cargar(entrada, lc);

	/* IMPRIMIR Y LIBERAR LISTA_CONTADORES*/
	imprimir(lc);

	exit(0);
}