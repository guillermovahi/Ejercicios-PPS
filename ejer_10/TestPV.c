#include <stdio.h>
#include <stdlib.h>

#include "pilavector.h"

/*
 * Informar acerca del consumo de memoria por las estructuras de datos
 * OJO: memoria estática
 */
void pvInfo() {
	printf("Info consumo de memoria:\n");
	printf("Tama\xA4o pdata (struct pilainfo):\t%ld bytes\n", sizeof(tdata));
	printf("Tama\xA4o pila == array pdata[50]:\t%ld bytes\n", sizeof(tpila));
	printf("Tama\xA4o pv (struct pilavector):\t%ld bytes\n", sizeof(tpv));
	printf("== == == == == == == == == == == == == == ==\n\n");
}


int main() {
	tdata a1, a2, a3;   // Tres alumnos/as potenciales

	pvInfo();           // Nada es gratis

	a1.id = 1;
	sprintf( a1.matricula, "mat_a1" );
	sprintf( a1.dni, "dni_a1" );
	sprintf( a1.nombre, "nombre_a1" );
	sprintf( a1.mail, "mail_a1" );
	a1.nota = 3.0;
	a2.id = 2;
	sprintf( a2.matricula, "mat_a2" );
	sprintf( a2.dni, "dni_a2" );
	sprintf( a2.nombre, "nombre_a2" );
	sprintf( a2.mail, "mail_a2" );
	a2.nota = 4.9;

	printf("Ini Test PilaVector\n");
	printf("===================\n");
	printf("===================\n\n");

	printf("PilaVector.init()\n");
	init();

	printf("================\n\n");
	printf("PilaVector.push()\n");
	push(a1);
	push(a2);
	display();

	printf("\n================\n\n");
	printf("PilaVector.llena()\n");
	if (llena()) {
		printf("\tPILA LLENA");
		printf("\n================\n\n");
	}

	printf("================\n\n");
	printf("PilaVector.pop()\n");
	a3 = pop();
    printf("pop retorna ID: %d; matricula: %s; dni: %s; nombre: %s; mail: %s\n", a3.id, a3.matricula, a3.dni, a3.nombre, a3.mail);
	display();
	printf("\n================\n\n");

	printf("PilaVector.vaciar()\n");
	vaciar();
	if (vacia()) {
		printf("\tPILA VACIA\n");
		printf("\n================\n\n");
	}
	return 0;
}
