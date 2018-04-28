#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){

  if (argc!=3){
    fprintf(stderr, "%s\n","Cantidad de parametros erronea");

    return 0;
  }

  FILE* f1;
  FILE* f2;

  if((f1 = fopen(argv[1],"r")) == NULL){
    fprintf(stderr, "%s\n","Archivo erroneo");

    return 0;
  }

  if((f2 = fopen(argv[2],"r")) == NULL){
    fprintf(stderr, "%s\n","Archivo erroneo");
    fclose(f1);

    return 0;
  }

  char* linea_f1 = NULL;
  char* linea_f2 = NULL;
  size_t capacidad_f1 = 0;
  size_t capacidad_f2 = 0;
  ssize_t read_f1;
  ssize_t read_f2;
  int posicicion = 1;

  read_f1 = getline(&linea_f1,&capacidad_f1,f1);
  read_f2 = getline(&linea_f2,&capacidad_f2,f2);

  while(read_f1 > EOF && read_f2 > EOF){

    if (strcmp(linea_f1, linea_f2) != 0) fprintf(stderr, "Diferencia linea %d\n<%s-------\n>%s\n",posicicion,linea_f1,linea_f2 );

    posicicion++;
    read_f1 = getline(&linea_f1,&capacidad_f1,f1);
    read_f2 = getline(&linea_f2,&capacidad_f2,f2);
  }

  if(read_f1 != read_f2 && (read_f1 == EOF || read_f2 == EOF) ){

    fprintf(stderr, "Diferencia linea %d\n<%s-------\n>%s\n",posicicion,read_f1 > EOF ? linea_f1 : " \n" , read_f2 > EOF ? linea_f2 : " \n"  );

    char* linea = NULL;
    size_t capacidad = 0;
    ssize_t read = getline(&linea,&capacidad, read_f1 > EOF ? f1 : f2 );


    while ( read > EOF){
      fprintf(stderr, "Diferencia linea %d\n<%s-------\n>%s\n",posicicion,read_f1 > EOF ? linea :" \n" , read_f2 > EOF ? linea : " \n"  );
      posicicion++;
      read = getline(&linea,&capacidad, read_f1 > EOF ? f1 : f2);
    }

    free(linea);
  }

  free(linea_f1);
  free(linea_f2);
  fclose(f1);
  fclose(f2);
  return 0;

}
