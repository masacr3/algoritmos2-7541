#include "cola.h"
#include <stdlib.h>


struct nodo;
typedef struct nodo nodo_t;

struct nodo {
  void *dato;
  nodo_t* siguiente;
};

struct cola {
  nodo_t* primero;
  nodo_t* ultimo;
};


/* *****************************************************************
 *                    PRIMITIVAS DEL NODO
 * *****************************************************************/
nodo_t* nodo_crear(void* dato){
  nodo_t* nodo = malloc(sizeof(nodo_t));

  if(!nodo) return NULL;

  nodo->dato = dato;
  nodo->siguiente = NULL;

  return nodo;
}


/* *****************************************************************
 *                    PRIMITIVAS DE LA COLA
 * *****************************************************************/

cola_t* cola_crear(void){
  cola_t* cola = malloc( sizeof(cola_t));

  if (!cola) return NULL;

  cola->primero = NULL;
  cola->ultimo = NULL;

  return cola;
}

void cola_destruir(cola_t *cola, void destruir_dato(void*)){

  while(!cola_esta_vacia(cola)){
    void* dato = cola_desencolar(cola);

    if(destruir_dato) destruir_dato(dato);
  }

free(cola);
}

bool cola_esta_vacia(const cola_t *cola){
  return !cola->primero;
}

bool cola_encolar(cola_t *cola, void* valor){
  nodo_t* nodo = nodo_crear(valor);

  if(!nodo) return NULL;

  if (cola_esta_vacia(cola)) cola->primero = nodo; else cola->ultimo->siguiente = nodo;

  cola->ultimo = nodo;

  return true;
}

void* cola_ver_primero(const cola_t *cola){
  return cola_esta_vacia(cola) ? NULL : cola->primero->dato;
}

void* cola_desencolar(cola_t *cola){

  if(cola_esta_vacia(cola)) return NULL;

  nodo_t* nodo = cola->primero;
  void* dato = nodo->dato;

  cola->primero = cola->primero->siguiente;

  free(nodo);

  if (cola_esta_vacia(cola)) cola->ultimo = NULL;

  return dato;
}
