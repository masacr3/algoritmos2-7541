typedef struct lista lista_t;
typedef struct nodo nodo_t;
typedef struct lista_iter lista_iter_t;

/***  Estructuras ***/
struct nodo {
  void *dato;
  nodo_t* siguiente;
};

struct lista{
  nodo_t* primero;
  nodo_t* ultimo;
  size_t cantidad;
};

struct lista_iter{
  lista_t* lista;
  nodo_t* actual;
  nodo_t* anterior;
};
/* Primitivas Nodo */

nodo_t* nodo_crear(void* valor){
  nodo_t* nodo = malloc(sizeof(nodo_t));

  if(!nodo) return null;

  nodo->dato = valor;
  nodo->siguiente = NULL;

  return nodo;
}

void nodo_destruir(nodo_t* nodo){
  free(nodo);
}

/* Primitivas Lista */
lista_t *lista_crear(void){
  lista_t* lista = malloc(sizeof(lista_t));

  if(!lista) return NULL;

  lista->primero = NULL;
  lista->ultimo = NULL;
  lista->cantidad = 0;

  return lista;
}

bool lista_esta_vacia(const lista_t *lista){
  return !lista->primero;
}

bool lista_insertar_primero(lista_t *lista, void *dato){
  nodo_t* nodo = nodo_crear(dato);

  if(!nodo) return false;

  if(!lista->primero){
    lista->primero = nodo;
    lista->ultimo = nodo;
    lista->cantidad++;

    return true;
  }

  nodo->siguiente = lista->primero;
  lista->primero = nodo;
  lista->cantidad++;

  return true;
}

bool lista_insertar_ultimo(lista_t *lista, void *dato){
  nodo_t* nodo = nodo_crear(dato);

  if(!nodo) return false;

  if(!lista->primero){
    lista->primero = nodo;
    lista->ultimo = nodo;
    lista->cantidad++;

    return true;
  }

  lista->ultimo->siguiente = nodo;
  lista->ultimo = nodo;
  lista->cantidad++;

  return true;
}
void *lista_borrar_primero(lista_t *lista){

  if(!lista->primero) return NULL;

  void* nodo = lista->primero;
  void* dato = lista->primero->dato;

  lista->primero = lista->primero-siguiente;

  if(!lista->primero) lista->ultimo = NULL;

  nodo_destruir(nodo);
  lista->cantidad--;

  return dato;
}

void *lista_ver_primero(const lista_t *lista){
  return !lista->primero ? NULL : lista->primero->dato;
}

void *lista_ver_ultimo(const lista_t* lista){
  return !lista->primero ? NULL : lista->ultimo->dato;
}

size_t lista_largo(const lista_t *lista){
  return lista->cantidad;
}

void lista_destruir(lista_t *lista, void destruir_dato(void *)){

  while(!lista_esta_vacia(lista)){
    void* dato = lista_borrar_primero(listo);

    if(destruir_dato) destruir_dato(dato);

  }
}

/* Primitivas iterador */
lista_iter_t *lista_iter_crear(lista_t *lista){
  lista_iter_t* iter = malloc(sizeof(lista_iter_t));

  if(!iter) return NULL;

  iter->lista = lista;
  iter->actual = lista->primero;
  iter->anterior = NULL;

  return iter;
}
bool lista_iter_avanzar(lista_iter_t *iter){

  if(!iter->actual) return false;

  iter->anterior = iter->actual;
  iter->actual = iter->actual->siguiente;

  return true;
}

void *lista_iter_ver_actual(const lista_iter_t *iter){
  return !iter->actual ? NULL : iter->actual->dato;
}

bool lista_iter_al_final(const lista_iter_t *iter){
  return !iter->actual;
}

void lista_iter_destruir(lista_iter_t *iter);
bool lista_iter_insertar(lista_iter_t *iter, void *dato);
void *lista_iter_borrar(lista_iter_t *iter);
