#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pila.h"

bool es_piramidal(pila_t *pila){
	bool ok = true;
	piramidal(pila,&ok);
	return ok;
}

int piramidal(pila_t*,bool *ok){
	int top =*(int*) pila_desapilar(pila);

	if(pila_esta_vacia(pila)){
		pila_apilar(pila,&top);
		*ok = true;
		return top;
	}

	int but = piramidal(pila,ok);

	*ok &= top > but;

	pila_apilar(pila,top);
	
	return top;
}
