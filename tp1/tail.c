#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cola.h"

int main(int argc, char* argv[]){

  if(argc != 2){
    fprintf(stderr, "%s\n", "Cantidad de parametros erronea" );
    return 0;
  }
  
  size_t imprimir = (size_t)atoi(argv[1]);

  if (imprimir == 0){
    fprintf(stderr, "%s\n", "Tipo de parametro incorrecto" );
    return 0;
  }

  char* linea = NULL;
  size_t capacidad = 0;
  cola_t* impresion_lineas = cola_crear();

  if (!impresion_lineas){
    fprintf(stderr, "%s\n", "A ocurrido un error" );
    return 0;
  }


  for (int i= 0; getline(&linea, &capacidad, stdin)>0; i++ ){
    size_t tam = strlen(linea)+2; // str + \n + \0
    char* guardar_linea = malloc(sizeof(char) * tam);

    if(!guardar_linea){
      fprintf(stderr, "%s\n", "A ocurrido un error inesperado" );
      while (!cola_esta_vacia(impresion_lineas)) free(cola_desencolar(impresion_lineas));
      break;
    }

    memcpy(guardar_linea,&linea[0],tam);

    if (i < imprimir){
      cola_encolar(impresion_lineas,guardar_linea);
    }
    else{
      char* cadena = cola_desencolar(impresion_lineas);
      cola_encolar(impresion_lineas,guardar_linea);
      free(cadena);
    }
  }

  while (!cola_esta_vacia(impresion_lineas)){
    char* imprimir_linea = cola_desencolar(impresion_lineas);
    fprintf(stdout, "%s", imprimir_linea );
    free(imprimir_linea);
  }

  free(linea);
  cola_destruir(impresion_lineas,NULL);
  return 0;
}
