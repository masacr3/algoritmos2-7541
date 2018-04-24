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
