#define _GNU_SOURCE
#include <stdio.h>
#include "syntax_val.h"
#include <stdlib.h>
#include <string.h>


int main(int argc, char** argv){

  char* linea = NULL;
  size_t capacidad = 0;

  while ( getline(&linea,&capacidad,stdin)>0){
    char* linea_actual = linea;
    bool ok = value_syntax(linea_actual);

    fprintf(stdout, "%s\n", !ok ? "ERROR" : "OK" );

  }

  free(linea);
  return 0;
}


bool in(char c, char* str){

  for (int i=0; str[i]; i++) if( c == str[i] ) return true;

  return false;
}


char char_opuesto(char c){
  return c == '{' ? '}' : c == '[' ? ']' : ')';
}


bool value_syntax(char* str){

  if (!str) return true;

  pila_t* pila = pila_crear();

  if(!pila){
    fprintf(stderr, "%s\n", "A ocurrido un error" );
    return false;
  }

  bool ok = true;
  bool comillas = false;

  for (int i=0; str[i]; i++){
    bool esta = in(str[i],"{}()[]");

    if (esta && !comillas){

        if ( in(str[i],"{([")){
          pila_apilar(pila,&str[i]);
        }
        else{

          if(pila_esta_vacia(pila)) {
            pila_destruir(pila);
            return false;
          }
          char* p = pila_desapilar(pila);

          if (*p == char_opuesto(*p) ){
            pila_destruir(pila);
            return false;
          }
        }

    }

    if ( str[i]=='\''){

      if( !comillas ) comillas = true;
      else comillas = false;
    }

  }
  ok = !pila_esta_vacia(pila) ? false : comillas ?  false : true;
  pila_destruir(pila);
  return ok;
}
