/*
 * Alumno: Leonel Rodrigo Rolon
 * Padron: 101009
 * fecha: 26-marzo-2018
 * code: C
 * Ejercicio: pila
 *
 * Facultad de Ingenieria, Universidad de Buenos Aires
 * Algoritmos II 75.41
 * */

#include "pila.h"
#include <stdlib.h>

#define PILA_VACIA 0
#define ARREGLO 10
#define AGRANDAR_PILA 2
#define ACHICAR_PILA 4
#define EXITOSO true
#define ERROR_MALLOC NULL;
#define ERROR_REDIMENSIONAR false

/* Definición del struct pila proporcionado por la cátedra.
 */
struct pila {
    void** datos;
    size_t cantidad;  // Cantidad de elementos almacenados.
    size_t capacidad;  // Capacidad del arreglo 'datos'.
};

/* *****************************************************************
 *                    PRIMITIVAS DE LA PILA
 * *****************************************************************/
pila_t* pila_crear(void){
  pila_t * pila = malloc( sizeof(pila_t) );

  if (!pila){
    return ERROR_MALLOC;
  }

  pila->datos = malloc (sizeof(void*) * ARREGLO);

  if (!pila->datos){
    pila_destruir(pila);
    return ERROR_MALLOC;
  }

  pila->cantidad = PILA_VACIA;
  pila->capacidad = ARREGLO;

  return pila;

}

void pila_destruir(pila_t *pila){
  free(pila->datos);
  free(pila);
}

bool pila_esta_vacia(const pila_t *pila){
  return pila->cantidad == PILA_VACIA;
}

bool redimencionar_pila(pila_t *t, tamanio){
  int ARREGLO_AUMENTADO = tamanio * AGRANDAR_PILA * sizeof(void*);
  void **datos_redimencionados = realloc(pila->datos, ARREGLO_AUMENTADO);
  if (!datos_redimencionados){
    return ERROR_REDIMENSIONAR;
  }
  pila->datos = datos_redimencionados;
  pila->capacidad = ARREGLO_AUMENTADO;
  return EXITOSO;
}

bool pila_apilar(pila_t *pila, void* valor){
  if (pila->capacidad == pila->cantidad){
    bool ok = redimencionar_pila(pila,AGRANDAR_PILA);
    if (!ok){
      return ERROR_REDIMENSIONAR;
    }
  }

  pila->datos[pila->cantidad++];
  return EXITOSO;
}

void* pila_ver_tope(const pila_t *pila){
  return pila_esta_vacia(pila) ? NULL : pila->datos[pila->cantidad-1];
}

void* pila_desapilar(pila_t *pila){
  bool condicion_redimencionar = pila->capacidad / 4 == pila->cantidad ;
  if (!pila_esta_vacia(pila) && condicion_redimencionar){
    bool ok = redimencionar_pila(pila,pila->capacidad / ACHICAR_PILA);
    if (!ok){
      return ERROR_REDIMENSIONAR;
    }
  }
  return pila->datos[--pila->cantidad] ;
}


// ...
