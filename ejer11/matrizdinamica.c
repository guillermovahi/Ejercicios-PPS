#include <stdio.h>
#include <stdlib.h>

long int **allocate_matrix(int m, int p);
void free_matrix(long int **matrix, int m, int p);
void fill_matrix_ones(long int **matrix, int m, int p);
void fill_matrix_rest(long int **matrix, int m, int p);
void show_matrix(long int **matrix, int m, int p);

int main(int argc, char *argv[])
{
	int m, p;
	long int **matrix;


	m = atoi(argv[1]);
	p = atoi(argv[2]);
	
	matrix = allocate_matrix(m, p);
	
	fill_matrix_ones(matrix, m, p);
	fill_matrix_rest(matrix, m, p);
	show_matrix(matrix, m, p);
	free_matrix(matrix, m, p);

	return 0;
}

long int **allocate_matrix(int m, int p)
{
	long int **matrix;
	int i;

	matrix = (long int **) malloc( m * sizeof(long int *)) ;
	
	if (matrix == NULL)
		exit(71);

	for (i = 0; i < m; i++)
	{
		matrix[i] = (long int *) malloc( p * sizeof(long int));
		if (matrix[i] == NULL)
			exit(71);
	}

	return matrix;
}

void free_matrix(long int **matrix, int m, int p)
{
	int i;

	for(i = 0; i < m; i++)
		free(matrix[i]);
	
	free(matrix);
}

void fill_matrix_ones(long int **matrix, int m, int p)
{
	int i,j;

	for(i = 0; i < m; i++)
	{
		for(j = 0; j < p; j++)
			matrix[i][j] = 1;
	}
	
}

void fill_matrix_rest(long int **matrix, int m, int p)
{
	int i,j;

	for(i = 1; i < m; i++)
	{
		for(j = 1; j < p; j++)
		{
			matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
			if (matrix[i][j] > 1000000)
				matrix[i][j] = 1; 
		}
			
	}
	
}

void show_matrix(long int **matrix, int m, int p)
{
	int i,j;

	for(i = 0; i < m; i++)
	{
		for(j = 0; j < p; j++)
			printf("%li\t", matrix[i][j]);
		printf("\n");	
	}

}

