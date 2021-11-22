#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char	c;
	int		n_espacios = atoi(argv[1]);
	int i;
	while ((c = getchar()) != EOF)
	{
		if (c == 32)
		{
			i = 1;
			while(i < n_espacios)
			{
				printf(" ");
				i++;
			}	
		}
		printf("%c",c);
	}
	return 0;
}