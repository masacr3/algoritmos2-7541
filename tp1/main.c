#include "util.h"
#include <stdio.h>

int main(){
  /* Test Util */
  printf("+++ Pruebas Util.h +++\n");

  //casos borde
  char* c1 = "marto,,gato";
  char* c2 = "marto,gato,";
  char* c3 = ",marto,gato";
  char* c4 = "";
  char* c5 = ",";
  char sep = ',';

  printf("\n~~~~~Test~~~~~~~~~~~~~~~~\n\n");
  printf("\n++ split ++\n");
  char** _split = split(c1,sep);
  printf("[");
  int i;
  for (i=0; _split[i+1]; i++) printf("%s - ",_split[i] );
  printf("%s ]\n",_split[i] );
  printf("\n~~~~~~~~###~~~~~~~~~~\n");
  char** _split2 = split(c2,sep);
  printf("[");
  for (int i=0; _split2[i]; i++) printf("%s - ",_split2[i] );
  printf("%s ]\n",_split2[i] );
  printf("\n~~~~~~~~###~~~~~~~~~~\n");
  printf("[");
  char** _split3 = split(c3,sep);
  for (int i=0; _split3[i]; i++) printf("%s - ",_split3[i] );
  printf("%s ]\n",_split3[i] );
  printf("\n~~~~~~~~###~~~~~~~~~~\n");
  char** _split4 = split(c4,sep);
  printf("[");
  for (int i=0; _split4[i]; i++) printf("%s - ",_split4[i] );
  printf("%s ]\n",_split4[i] );
  printf("\n~~~~~~~~###~~~~~~~~~~\n");
  char** _split5 = split(c5,sep);
  printf("[");
  for (int i=0; _split5[i]; i++) printf("%s - ",_split5[i] );
  printf("%s ]\n",_split5[i] );
  printf("\n~~~~~~~~###~~~~~~~~~~\n");

  printf("++fin pruebas++\n" );
  free_strv(_split);
  free_strv(_split2);
  free_strv(_split3);
  free_strv(_split4);
  free_strv(_split5);
  return 0;
}
