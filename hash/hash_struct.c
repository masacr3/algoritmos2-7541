#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"
#include "hash.h"
/*
    estructura del hash abierto

*/

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

/* falta las estructuras de los iteradores
    lo tenes que hacer vos marto
*/
