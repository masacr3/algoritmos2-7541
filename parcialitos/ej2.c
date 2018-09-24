#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_lista {
	struct nodo_lista* prox;
	void *dato;
} nodo_lista_t;

typedef struct lista{
	nodo_lista_t* prim;
}lista_t;

void* ante_k_ultimo(lista_t*,size_t k){
	nodo_lista_t* prim = lista_t->prim;
	nodo_lista_t* k_ult = lista->prim;

	for (int i = 0; i < k; i++){
		prim = prim->prox;
	}

	while (prim->prox){
		prim = prim->prox;
		k_ult = k_ult->prox;
	}
	
	return k_ult->dato;
}
