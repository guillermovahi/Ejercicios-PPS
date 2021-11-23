#define MAXPILA 50

#include "pilainfo.h"

/*
 * Este tipo es la propia pila, implementada como un array (el contenedor)
 * de MAXPILA (50) unidades tipo pdata (el contenido)
 */
typedef tdata tpila[MAXPILA];

/*
 * El tipo pilavector define la pila y el indice a la cima
 * Se accederá mediante los habituales servicios push/pop
 */
typedef struct pilavector {
   tdata datos[MAXPILA];
//   tpila datos2;     // Equivalente a lo anterior. Da igual, no sea que alguien se deprima
   int top;
} tpv;

/**
 * Cabeceras de las funciones en pilavector.c
 */

/*
 * Inicializar todos los contenedores en la pila a 0 y la cima a -1 (indica vacía)
 */
void init(void);

/*
 * Restaurar la pila al estado inicial
 */
void vaciar(void);

/*
 * Comprobar si está llena. Devuelve 1 si lo está y 0 en caso contrario
 */
int llena(void);

/*
 * Comprobar si está vacía. Devuelve 1 si lo está y 0 en caso contrario
 */
int vacia(void);

/*
 * Operación push: apila item
 * Devuelve 0 si apila y -1 en caso contrario
 */
int push(tdata item);

/*
 * Operación pop: devuelve el contenido en la cima de la pila
 * En la cima hay un item especial que marca vacía
 */
tdata pop(void);

/*
 * Mostrar el contenido de la pila
 */
void display(void);
