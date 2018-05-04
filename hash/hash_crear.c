hash_t* hash_creaar(hash_destruir_dato_t destruir_dato){
  hash_t* hash=malloc(sizeof(hash_t));
  if (!hash) return NULL;
  hash->tabla=malloc(sizeof(lista_t)*TAMANIO);
  if (!hash->tabla){
    free(hash);
    return NULL;
  }
  hash->capacidad=TAMANIO;
  hash->cantidad=CANTIDAD_INICIAL;
  hash->dato=destruir_dato;
  return hash;
}
