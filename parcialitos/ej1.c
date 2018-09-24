#include <stdio.h>
#include <stdlib.h> //typedef
#include "pila.h"

typedef struct compo composicion_t;
typedef double (*fun_t)(double);

struct compo{
	pila_t* funciones;
};


//prototipe function
composicion_t* conposicion_crear();
void composicion_destruir(composicion_t*);
bool composicion_agregar_funcion(composicion_t*,double(f)(double));
double composicion_aplicar(composicion_t*,double);

composicion_t* composicion_crear(){
	composicion_t* comp = malloc(sizeof(composicion_t));
	if (!comp) return NULL;
	comp->funciones = pila_crear();
	if(!comp->funciones){
		free(comp);
		return NULL;
	}
	return comp;
}

void composicion_destruir(composicion_t* comp){
	pila_destruir(comp->funciones);
	free(comp);
}

bool composicion_agregar_funcion(composicion_t *comp, double (f) (double) ){
	if (!f) return false;
	return pila_apilar(comp->funciones,f);
}

doble composicion_aplicar(composicion_t *comp, double n ){

	while( !pila_esta_vacia(comp->funciones) ){
		fun_t f =(fun_t) pila_desapilar(comp->funciones);
		n = f(n);
	}

	return n;
}		
