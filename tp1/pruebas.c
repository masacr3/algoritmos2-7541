#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "strutil.h"


char* new(char*);

int main(){
  char** s = (char**)malloc(sizeof(char*));
  s[0] = NULL;

  char** s1 = (char**)malloc(sizeof(char*)*2);
  s1[0] = new("");
  s1[1] = NULL;

  char** s2 = (char**)malloc(sizeof(char*)*2);
  s2[0] = new("abc");
  s2[1] = NULL;

  char** s3 = (char**)malloc(sizeof(char*)*3);
  s3[0] = new("");
  s3[1] = new("");
  s3[2] = NULL;

  char* c = join(s,',');
  char* c1 = join(s1,',');
  char* c2 = join(s2,',');
  char* c3 = join(s3,',');
  printf("[]  join(,) -> %s\n",c[0]=='\0' ? "''" : "fail" );
  printf("['']  join(,) -> %s\n",c1[0]=='\0' ? "''" : "fail" );
  printf("['abc']  join(,) -> %s\n",!strcmp(c2,"abc") ? "'abc'" : "fail" );
  printf("['','']  join(,) -> %s\n",!strcmp(c3,",") ? "','" : "fail" );


  free_strv(s);
  free_strv(s1);
  free_strv(s2);
  free_strv(s3);
  free(c);
  free(c1);
  free(c2);
  free(c3);
  return 0;

}

//no me anda strdup lo emule UU.
char* new(char* str){
  size_t p = strlen(str);

  char* c = malloc(sizeof(char)*p+1);
  if (!c) return NULL;

  memcpy(c,&str[0],p);
  c[p]='\0';

  return c;
}
