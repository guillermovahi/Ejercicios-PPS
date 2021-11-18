#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *array_of_ints;
    int i;
	int x;
	array_of_ints = malloc(sizeof(int));
	i = 0;
	while(scanf("%i", &x))
	{
		array_of_ints[i] = x;
		i++; 
	}
	while(--i>=0)
		fprintf(stdout,"%i\n",array_of_ints[i]);
		
    return 0;
}
