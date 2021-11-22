#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *archivo;
    int *arr;
    char caracteres[1000];
    int i;
    
    archivo = fopen(argv[1], "r");
    if (archivo == NULL)
        exit(1);
    else
    {   
        arr = malloc(sizeof(int));
        i = 0;
        while (feof(archivo) == 0 && i < 1000)    
 	    {
            fgets(caracteres, 100, archivo);
            //int dif  = strcmp(caracteres,"0\n");
            //printf("diferencia[%d]: %d\n",i,dif);
            if (atoi(caracteres) != 0)//|| strcmp(caracteres,"0\n") == 3) 
                arr[i] = atoi(caracteres);
            else
                break; 
            i++;
 	    }
    }
    //i--;
    fclose(archivo); 
    while(i >= 0)
        printf("%d\n",arr[i--]);

    return 0;
}
