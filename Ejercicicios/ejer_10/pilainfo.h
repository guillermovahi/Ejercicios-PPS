/*
 * Este tipo define la información que contiene la pila (el contenido)
 */
typedef struct pilainfo
{
     int id;
     char matricula[10];
     char dni[10];
     char nombre[50];
     char mail[50];
     float nota;
} tdata;

/*
 * Este tipo define un tipo puntero al tipo de dato que contiene la pila (el contenido)
 * No es necesario puesto que C los argumentos tipo struct son referencias
 */
typedef tdata *ptr;
