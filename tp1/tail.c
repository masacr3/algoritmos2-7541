#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

  size_t imprimir = argc == 1 ? 0 : atoi(argv[1]);

  if(argc == 1){
    fprintf(stderr, "%s\n", "Cantidad de parametros erronea" );
    return 0;
  }

  if (imprimir<1){
    fprintf(stderr, "%s\n", "Tipo de parametro incorrecto" );
    return 0;
  }

  char* linea = NULL;
  size_t capacidad = 0;

  while (getline(&linea, &capacidad, stdin)>0 && imprimir--) fprintf(stdout, "%s",linea);
  free(linea);
  return 0;
}
