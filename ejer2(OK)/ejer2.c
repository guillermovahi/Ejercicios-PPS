#include <stdio.h>
#include <stdlib.h>

void assign_size(int m, int n, int p);
void fill_matrix(int m, int n, int p, int mat1[m][n], int mat2[n][p]);
void mult_matrix(int m, int n, int p, int mat1[m][n], int mat2[n][p]);

int main(int argc, char *argv[])
{
	int m; // m filas de la primera matriz
	int n; // n columnas de la primera matriz y n filas de la segunda matriz
	int p; // p columnas  segunda matriz
	
	// Asignamos las dimensiones de la matriz
	assign_size(m,n,p);

	return 0;
}

void assign_size(int m, int n, int p)
{
	int i; // contador
	int num; 

	i = -1;
	while(++i < 3 && scanf("%i", &num))
	{
		if (i == 0)
			m = num;
		else if (i == 1)
			n = num;
		else
			p = num;	
	}


	int mat1[m][n];
	int mat2[n][p];
	
	fill_matrix(m, n, p, mat1, mat2);
	mult_matrix(m, n, p, mat1, mat2);

}

void fill_matrix(int m, int n, int p, int mat1[m][n], int mat2[n][p])
{
	int i;
	int j;
	char string[1000];

	//Rellenar Primera Matriz
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++){
			scanf("%s", &string);
			mat1[i][j] = atoi(string);
		}
	}

	//Rellenar Segunda Matriz
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < p; j++){
			scanf("%s", &string);
			mat2[i][j] = atoi(string);
		}
	}

}

void mult_matrix(int m, int n, int p, int mat1[m][n], int mat2[n][p])
{
	int	i, j, k;
	int mat_res[m][p];

	for(i = 0; i < m; i++)
	{
		for(j = 0; j < p; j++)
			mat_res[i][j] = 0;
	}	

	for(i = 0; i < m; i++)
	{
		for(j = 0; j < p; j++){
			for(k = 0; k < n; k++)
				mat_res[i][j] += mat1[i][k] * mat2[k][j];
		}
	}

	for(i = 0; i < m; i++)
	{
		for(j = 0; j < p; j++)
			printf("%i ", mat_res[i][j]);
		printf("\n");
	}	
}
