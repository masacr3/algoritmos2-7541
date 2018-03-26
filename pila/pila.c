/*
 * Alumno: Leonel Rodrigo Rolon
 * Padron: 101009
 * fecha: 25-marzo-2018
 * code: C
 * Ejercicio: pila
 *
 * Facultad de Ingenieria, Universidad de Buenos Aires
 * Algoritmos II 75.41
 * */
#include "pila.h"
#include <stdlib.h>

#define PILA_VACIA 0
#define BASE_ARRAY 10
#define AUMENTAR 2

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

// pila_crear
void configuracion_miembros_pila(pila_t *pila, size_t cantidad, size_t capacidad){
  pila->cantidad = cantidad;
  pila->capacidad = capacidad;
}

pila_t* _pila_creada(pila_t *pila, size_t cantidad, size_t capacidad){
  configuracion_miembros_pila(pila,cantidad,capacidad);
  return pila;
}

void* destruir_datos(pila_t *pila){
  pila_destruir(pila);
  return NULL;
}

pila_t* _crear_datos(pila_t *pila){
  pila->datos = malloc(sizeof(void*) * BASE_ARRAY);
  return !pila->datos ? destruir_datos(pila) : _pila_creada(pila,PILA_VACIA,BASE_ARRAY);
}

pila_t* pila_crear(void){
  pila_t *pila = malloc(sizeof(pila_t));
  return !pila ? NULL : _crear_datos(pila);
}

//fin pila crear

void pila_destruir(pila_t *pila){
  free(pila->datos);
  free(pila);
}

bool pila_esta_vacia(const pila_t *pila){
  return pila->cantidad == PILA_VACIA;
}

//pila_ver_tope
void* _ver_tope(const pila_t *pila){
  return pila->datos[pila->cantidad -1];
}

void* pila_ver_tope(const pila_t *pila){
  return pila_esta_vacia(pila) ? NULL : _ver_tope(pila);
}
//fin pila_ver_tope

bool _apilar(pila_t *pila, void* valor){
  pila->datos[pila->cantidad] = valor;
  pila->cantidad++;
  return true;
}

bool agrandar_pila(pila_t *pila, void* valor){
  int nuevo_tamanio  = datos->capacidad * AUMENTAR * sizeof(void*);
  void **datos_redimencionados = realloc(pila->datos, nuevo_tamanio);

  if (!datos_redimencionados) {
    return NULL;
  }

  pila->datos = datos_redimencionados;
  configuracion_miembros_pila(pila,pila->cantidad,nuevo_tamanio);
  return _apilar(pila,valor)

}

bool pila_apilar(pila_t *pila, void* valor){
  return pila->cantidad == pila->capacidad ? agrandar_pila(pila,valor) : _apilar(pila,valor);
}

bool _apilar(pila_t *pila, void* valor){
  pila->datos[pila->cantidad] = valor;
  pila->cantidad++;
  return true;
}

void* _desapilar(pila_t *pila, void* valor){
  void *valor = pila_ver_tope(pila);
  pila->cantidad--;
  return valor;
}

void* achicar_pila(pila_t *pila, void* valor){
  int nuevo_tamanio  = datos->capacidad / AUMENTAR * sizeof(void*);
  void **datos_redimencionados = realloc(pila->datos, nuevo_tamanio);

  if (!datos_redimencionados) {
    return NULL;
  }

  pila->datos = datos_redimencionados;
  configuracion_miembros_pila(pila,pila->cantidad,nuevo_tamanio);
  return _desapilar(pila,valor)
}


void* _desapilar_pila(pila_t *pila){
  return (pila->capacidad / 4 == pila->cantidad && pila->cantidad > 0) ? achicar_pila(pila,valor) : _desapilar(pila,valor);
}

void* pila_desapilar(pila_t *pila){
  return pila_esta_vacia(pila) ? NULL : _desapilar_pila(pila);
}

// ...
