#include "util.h"
#include <stdio.h>

int main(){
  /* Test Util */
  printf("+++ Pruebas Util.h +++\n");

  char* c = "marto,gato";
  char sep = ',';
  int* a = buscar_sep(c,sep);

  printf("cadena -> %s\n",c );
  printf("separador ->[%c]\n",sep);
  printf("coincidencias %d\n",a[0]);
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("\n++ split ++\n");
  char** _split = split(c,sep);
  for (int i=0; _split[i]; i++) printf("%s\n",_split[i] );


  printf("++fin pruebas++\n" );
  free(a);
  free_strv(_split);
  return 0;
}
