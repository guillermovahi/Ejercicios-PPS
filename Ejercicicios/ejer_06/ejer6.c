#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char c;
	char otro;
	char *cadena;
	int i;
	cadena = malloc(100);
	i = 0;
	while((c = getchar()) != 10)
	{
		if (c == '\\')
		{
			otro=getchar();
			if (otro == 't')
				cadena[i++] = '\t';
			else if(otro == 'n')
				cadena[i++] = '\n';
			else
			{
				cadena[i++] = c;
				cadena[i++] = otro;
			}	
		}
		else
			cadena[i++] = c;
	}	
	printf("\"%s\".\n",cadena);

	return 0;
}