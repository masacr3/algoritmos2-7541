/*
 * Alumno: Leonel Rodrigo Rolon
 * Padron: 101009
 * fecha: 24-marzo-2018
 * code: C
 * Ejercicio: vector dinamico
 *
 * Facultad de Ingenieria, Universidad de Buenos Aires
 * Algoritmos II 75.41
 * */

#include "vector_dinamico.h"


// Funciones del alumno.

size_t vector_obtener_tamanio(vector_t* vector){
  return vector->tam;
}

void vector_destruir(vector_t* vector){
  free(vector->datos);
  free(vector);
}

bool vector_guardar(vector_t* vector, size_t pos, int valor){
  bool vector_fuera_rango = pos>= vector_obtener_tamanio(vector) || pos < 0;

  if (vector_fuera_rango) return false;

  vector->datos[pos] = valor;
  return true;
}

bool vector_obtener(vector_t* vector, size_t pos, int* valor){
  bool vector_fuera_rango = pos>= vector_obtener_tamanio(vector) || pos < 0;

  if (vector_fuera_rango) return false;

  *valor = vector->datos[pos];
  return true;
}
// ...

// Funciones implementadas por la catedra.

vector_t* vector_crear(size_t tam) {
    vector_t* vector = malloc(sizeof(vector_t));

    if (vector == NULL) return NULL;

    vector->datos = malloc(tam * sizeof(int));

    if (tam > 0 && vector->datos == NULL) {
        free(vector);
        return NULL;
    }
    vector->tam = tam;
    return vector;
}

bool vector_redimensionar(vector_t* vector, size_t tam_nuevo) {
    int* datos_nuevo = realloc(vector->datos, tam_nuevo * sizeof(int));

    // Cuando tam_nuevo es 0, es correcto si se devuelve NULL.
    // En toda otra situación significa que falló el realloc.
    if (tam_nuevo > 0 && datos_nuevo == NULL) {
        return false;
    }

    vector->datos = datos_nuevo;
    vector->tam = tam_nuevo;
    return true;
}
