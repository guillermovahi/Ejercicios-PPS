#include <stdio.h>
#include <math.h> //Es 100% necesario para hacer una raíz cuadrada?

int resolver(double a, double b, double c, double *px1, double *px2);

int main(int argc, char *argv[])
{
	double a, b, c, *px1, *px2;
	int res;

	scanf("%lf %lf %lf", &a, &b, &c);
	res = resolver(a, b, c, px1, px2);
	if (res == 0)
		fprintf(stdout, "No-Compleja");
	else
		fprintf(stdout, "Compleja");
		
	return 0;
}

int resolver(double a, double b, double c, double *px1, double *px2)
{
	int res = 0;
	double n1,n2,n3, solucion1, solucion2;
	double raiz, real, imag;
	double nan = sqrt(-1.0); //NAN

	printf("-------------------------------------\n");
	printf("La ecuacion que se va a resolver es: %fx^2 + %fx + %f = 0\n",a,b,c);
	
	
	if(a == 0 && b == 0) //No existe solución (3)
	{
		px1 = &nan;
		px2 = &nan;

		printf("px1: %lf\npx2: %lf\n",*px1, *px2);
		
		return res;

	}
	else if(a == 0) //Ecuación de Primer grado (4)
	{
		solucion1 = -c/b; //x = -c/b

		px1 = &solucion1;
		px2 = &nan;

		printf("px1: %lf\npx2: %lf\n",*px1, *px2);
		
		return res;
	}

	raiz = (b*b)-4*a*c;

	if (raiz < 0) //Soluciones imaginarias (2)
	{
		res = 1;
		raiz = raiz * (-1);
		real = -b / (2*a);
		imag = (sqrt(raiz)/(2*a)); // se multiplica x nan???;

		px1 = &real;
		px2 = &imag;

		printf("px1: %lf\npx2: %lf\n",*px1, *px2);
		
	}
	else if(raiz == 0) //Ecuación de Segundo grado 1 solución (4)
	{
		solucion1 = -b/(2*a);

		px1 = &solucion1;
		px2 = &nan;

		printf("px1: %lf\npx2: %lf\n",*px1, *px2);
	}
	else //Ecuación de Segundo grado 2 soluciones (1)
	{
		n1 = (-b + sqrt(raiz))/(2*a);
		n2 = (-b - sqrt(raiz))/(2*a);

		solucion1 = n1;
		solucion2 = n2;
		
		px1 = &solucion1;
		px2 = &solucion2;
		
		printf("px1: %lf\npx2: %lf\n",*px1, *px2);
	}
		
	return res; //delvovemos 1 si es compleja, 0 si no lo es
}

