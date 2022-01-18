/* HOJA 1 */
#include "ExEne21.h"

lista_lineas *lista = NULL;

int main(int argc, char const *argv[])
{
	/* 1ª PARTE: PROCESADO DE ARGUMENTOS */
	if(argc != 4)
	{
		fprintf(stderr, "ERROR: número de argumentos incorrecto\n");
		exit(64);
	}

	FILE *f1, *f2;

	f1 = fopen(argv[1], "r");
	if(f1 == NULL)
	{
		fprintf(stderr, "ERROR: No se ha podido abrir el archivo %s\n", argv[1]);
		exit(66);
	}
	
	f2 = fopen(argv[3], "r");
	if(f2 == NULL)
	{
		fprintf(stderr, "ERROR: No se ha podido abrir el archivo %s\n", argv[3]);
		exit(66);
	}

	/* 2ª PARTE: CARGA EN MEMORIA DINÁMICA */
	lista = cargar_f1(f1);
	if(lista == NULL)
		exit(71);
	
	/* 3ª PARTE: UNIR LÍNEAS FICH1 y FICH2 */
	unir_f1_f2(f2, argv[2], lista);

	/* 4ª PARTE: SALIDA ORDENADA */
	liberar(lista);
	fclose(f2);
	fclose(f1);
	
	exit(0);
}
