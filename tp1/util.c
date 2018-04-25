/*
 * Leonel R.
 */
char* slice(const char* str, size_t inicio, size_t fin){
  size_t largo = fin - inicio;

  if(!largo) return strdup("");

  char* cad = (char*)malloc(sizeof(char) * (largo+1));

  if(!cad) return NULL;

  memcpy(cad,&str[inicio],largo-1);
  cad[largo]='\0';

  return cad;
}

/*
 * Devuelve las posiciones donde esta SEP
 * posiciones[0] guarda el tamaño del array
 * posiciones[>0] se guardan las posiciones relativas de SEP
 * Post:
 *   >   si no hay coincidencias posiciones[0] = 0
 *   >   si hay coincidencias posiciones[0] = coincidencias , len(posiciones) = coincidencias    
 */
int* buscar_sep(const char* str, char* sep){
  size_t coincidencias = 0;
  int* posiciones = malloc(sizeof(int));

  if(!posiciones) return NULL;

  posiciones[0] = 0;

  for (int i=0; str[i]; i++) if(str[i]==sep) coincidencias++;

  if (!coincidencias) return posiciones;

  posiciones[0] = coincidencias;
  posiciones = realloc(posiciones, sizeof(int) * posiciones);

  if(!posiciones) return NULL;

  int k=0;
  for(int i=0; str[i]; i++){

    if(str[i]==sep){
      posicion[k++] = i;
      coincidencias--;
    }

    if(!coincidencias) break;

  }

  return posiciones;
}
