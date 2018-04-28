/*
 * Facultad de Ingenieria Universidad de Buenos Aires
 *
 * Autor: Leonel R. Rolon
 *
 * Code: C
 *
 * Date: 26-abril-2018
 */
#include "strutil.h"
#include <string.h>


char* slice(const char* str, size_t inicio, size_t fin){
  size_t largo = fin - inicio;
  size_t tam = largo +1;

  char* cad = (char*)malloc(sizeof(char) * tam );

  if(!cad) return NULL;

  memcpy(cad,&str[inicio],largo);

  cad[largo]='\0';

  return cad;
}


int* buscar_sep(const char* str, char sep){
  size_t coincidencias = 0;

  int* posiciones = malloc(sizeof(int));

  if(!posiciones) return NULL;

  posiciones[0] = 0;

  for (int i=0; str[i]; i++) if(str[i]==sep) coincidencias++;

  if (!coincidencias) return posiciones;

  posiciones[0] = (int)coincidencias;
  posiciones = realloc(posiciones, sizeof(int) * (coincidencias + 1));

  if(!posiciones) return NULL;

  int k=1;
  for(int i=0; str[i]; i++){

    if(str[i]==sep){
      posiciones[k++] = i;
      coincidencias--;
    }

    if(!coincidencias) break;

  }

  return posiciones;
}


/*
 * Autor: Leonel R.
 *
 * Complexity : O(n)
 */
char** split(const char* str, char sep){
  if (sep == '\0') return NULL;
  
  int* posiciones_sep = buscar_sep(str,sep);
  if (!posiciones_sep) return NULL;

  size_t apariciones = (size_t)posiciones_sep[0];
  size_t tam_split = apariciones + 2;

  char** _split = (char**)malloc(sizeof(char*) * tam_split );

  if(!_split){
    free(posiciones_sep);
    return NULL;
  }

  _split[0] = slice(str,0,!apariciones ? strlen(str) : (size_t)posiciones_sep[1] );

  _split[ tam_split -1 ] = NULL;

  if (apariciones) _split[apariciones] = slice(str,(size_t)posiciones_sep[apariciones]+1,strlen(str));

  for (int i=1; i < apariciones; i++) _split[i] = slice(str,(size_t)posiciones_sep[i]+1,(size_t)posiciones_sep[i+1]);

  free(posiciones_sep);

  return _split;

}

void free_strv(char *strv[]){
    for (int i = 0; strv[i]; i++) {
        free(strv[i]);
    }
	free(strv);
}
