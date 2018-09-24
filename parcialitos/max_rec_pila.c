#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pila.h"

int maximo_pila(pila_t *pila){
	return max_pila(pila);
}

int max_pila(pila_t *pila){
	int n = *(int*) pila_desapilar(pila);

	if ( pila_esta_vacia(pila) ){
		pila_apilar(pila,&n);
		return n;
	}

	int max = max_pila(pila);

	if (max < n ) max = n;

	pila_apilar(pila,&n);

	return max;
}
