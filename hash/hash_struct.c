#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"
#include "hash.h"
/*
    estructura del hash abierto
*/

#define TAMANIO 100
#define CANTIDAD_INICIAL 0

struct hash{
  lista_t** tabla;
  size_t capacidad; //tamaño del tabla filas
  size_t cantidad; // cantidad de elementos totales
  hash_destruir_dato_t destruir_dato;
};

typedef struct campo{
  char* clave;
  void* dato;
};

struct hash_iter {
  const hash_t hash;
  lista_iter_t* iter_lista;
  size_t cantidad; // cantidad de elemento que itero
  size_t indice_actual; // indice actual;
};
