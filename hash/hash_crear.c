hash_t *hash_crear(hash_destruir_dato_t destruir_dato){
  hash_t* hash = malloc(sizeof(hash_t));

  if(!hash) return NULL;

  //tenemos que tener un tamanio inicial

  lista_t** tabla = (lista_t**) malloc(sizeof(lista_t*) * TAM_INICIAL);

  if(!tabla){
    free(hash);
    return NULL;
  }

  hash->tabla = tabla;

  for(int i=0 ; i < TAM_INICIAL ; i++) hash->tabla[i] = lista_crear();

  hash->capacidad = TAM_INICIAL;
  hash->cantidad = 0;
  hash->destructor = destruir_dato;

  return hash;
}
