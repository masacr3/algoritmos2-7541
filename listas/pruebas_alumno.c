#include "lista.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void pruebas_lista_vacia(){
  printf("PRUEBAS LISTA VACIA \n");

  lista_t* lista = lista_crear();
  print_test("La lista esta creada", lista != NULL);
  print_test("La lista esta vacia", lista_esta_vacia(lista) );

  print_test("Ver primero es una operacion invalida", !lista_ver_primero(lista));
  print_test("Ver ultimo es una operacion invalida", !lista_ver_ultimo(lista));
  print_test("Borrar primero es una operacion invalida", !lista_borrar_primero(lista));
  print_test("El largo de la lista es 0", lista_largo(lista) == 0);
  lista_destruir(lista,NULL);
  print_test("lista destruida",true);
}

void pruebas_lista_insertar_primero_sin_elementos_dinamicos(){
  printf("PRUEBAS LISTA INSERTAR PRIMERO SIN ELEMENTOS DINAMICOS \n");

  lista_t* lista = lista_crear();
  print_test("La lista esta creada", lista != NULL);
  print_test("La lista esta vacia", lista_esta_vacia(lista) );

  int array [] = {1, 2, 3, 4 , 5};

  bool inserto_ok = true;

  for (int i = 0; i < 5; i++) inserto_ok &= lista_insertar_primero(lista,&array[i]) && *(int*)lista_ver_primero(lista) == array[i];

  print_test("Se insertaron todos los elementos correctamente",inserto_ok);

  bool borraron_ok = true;

  for (int i = 0; i < 5; i++) borraron_ok &= *(int* )lista_borrar_primero(lista) == array[5-1-i];

  print_test("Se borraron todos los elementos",borraron_ok);
  print_test("La lista tiene que estar vacia",lista_esta_vacia(lista));
  lista_destruir(lista,NULL);
  print_test("lista destruida",true);

}

void pruebas_lista_insertar_primero_con_elementos_dinamicos(){
  printf("PRUEBAS LISTA INSERTAR PRIMERO CON ELEMENTOS DINAMICOS \n");

  lista_t* lista = lista_crear();
  print_test("La lista esta creada", lista != NULL);
  print_test("La lista esta vacia", lista_esta_vacia(lista) );

  int** array =malloc(sizeof(int*)*5);
  bool array_ok = true;

  if (!array) array_ok = false;


  for(int i=0; i<5; i++){
    array[i] = malloc(sizeof(int));
    if(!array[i]) array_ok = false;
  }

  for (int i=0; i<5; i++){
    *array[i] = i;
  }

  //for (int i=0; i<5; i++) printf("%d -> %d \n",i+1,*(int*)array[i]);
  print_test("Se creo los datos dinamicos", array_ok);

  bool inserto_ok = true;

  for (int i = 0; i < 5; i++) inserto_ok &= lista_insertar_primero(lista,array[i]) && *(int*)lista_ver_primero(lista) == i;

  print_test("Se insertaron todos los elementos correctamente",inserto_ok);

  bool borraron_ok = true;

  for (int i = 0; i < 5; i++){
    int* numero = lista_borrar_primero(lista);
    borraron_ok &= *numero == 5-1-i;
    free(numero);
  }
  print_test("Se borraron todos los elementos",borraron_ok);
  print_test("La lista tiene que estar vacia",lista_esta_vacia(lista));
  lista_destruir(lista,NULL);
  free(array);
  print_test("lista destruida",true);

}

void pruebas_lista_insertar_ultimo_sin_elementos_dinamicos(){
  printf("PRUEBAS LISTA INSERTAR ULTIMO SIN ELEMENTOS DINAMICOS \n");

  lista_t* lista = lista_crear();
  print_test("La lista esta creada", lista != NULL);
  print_test("La lista esta vacia", lista_esta_vacia(lista) );

  int array [] = {1, 2, 3, 4 , 5};

  bool inserto_ok = true;

  for (int i = 0; i < 5; i++) inserto_ok &= lista_insertar_ultimo(lista,&array[i]) && *(int*)lista_ver_ultimo(lista) == array[i];

  print_test("Se insertaron todos los elementos correctamente",inserto_ok);

  bool borraron_ok = true;

  for (int i = 0; i < 5; i++) borraron_ok &= *(int* )lista_borrar_primero(lista) == array[i];

  print_test("Se borraron todos los elementos",borraron_ok);
  print_test("La lista tiene que estar vacia",lista_esta_vacia(lista));
  lista_destruir(lista,NULL);
  print_test("lista destruida",true);

}

void pruebas_lista_insertar_ultimo_con_elementos_dinamicos(){
  printf("PRUEBAS LISTA INSERTAR ULTIMO CON ELEMENTOS DINAMICOS \n");

  lista_t* lista = lista_crear();
  print_test("La lista esta creada", lista != NULL);
  print_test("La lista esta vacia", lista_esta_vacia(lista) );

  int** array =malloc(sizeof(int*)*5);
  bool array_ok = true;

  if (!array) array_ok = false;


  for(int i=0; i<5; i++){
    array[i] = malloc(sizeof(int));
    if(!array[i]) array_ok = false;
  }

  for (int i=0; i<5; i++){
    *array[i] = i;
  }

  //for (int i=0; i<5; i++) printf("%d -> %d \n",i+1,*(int*)array[i]);
  print_test("Se creo los datos dinamicos", array_ok);

  bool inserto_ok = true;

  for (int i = 0; i < 5; i++) inserto_ok &= lista_insertar_ultimo(lista,array[i]) && *(int*)lista_ver_ultimo(lista) == i;

  print_test("Se insertaron todos los elementos correctamente",inserto_ok);

  bool borraron_ok = true;

  for (int i = 0; i < 5; i++){
    int* numero = lista_borrar_primero(lista);
    borraron_ok &= *numero == i;
    free(numero);
  }
  print_test("Se borraron todos los elementos",borraron_ok);
  print_test("La lista tiene que estar vacia",lista_esta_vacia(lista));
  lista_destruir(lista,NULL);
  free(array);
  print_test("lista destruida",true);

}

void pruebas_lista_volumen_sin_elementos_dinamicos(){
  printf("PRUEBAS LISTA VOLUMEN SIN ELEMENTOS DINAMICOS \n");

  lista_t* lista = lista_crear();
  print_test("La lista esta creada", lista != NULL);
  print_test("La lista esta vacia", lista_esta_vacia(lista) );

  int array [2000] ;

  bool inserto_ok = true;

  for (int i = 0; i < 2000; i++) {
    array[i] = i;
    inserto_ok &= lista_insertar_ultimo(lista,&array[i]) && *(int*)lista_ver_ultimo(lista) == array[i];
  }
  print_test("Se insertaron todos los elementos correctamente",inserto_ok);

  bool borraron_ok = true;

  for (int i = 0; i < 2000; i++) borraron_ok &= *(int* )lista_borrar_primero(lista) == array[i];

  print_test("Se borraron todos los elementos",borraron_ok);
  print_test("La lista tiene que estar vacia",lista_esta_vacia(lista));
  lista_destruir(lista,NULL);
  print_test("lista destruida",true);
}

void pruebas_lista_volumen_con_elementos_dinamicos(){
  printf("PRUEBAS LISTA VOLUMEN CON ELEMENTOS DINAMICOS \n");

  lista_t* lista = lista_crear();
  print_test("La lista esta creada", lista != NULL);
  print_test("La lista esta vacia", lista_esta_vacia(lista) );

  int** array =malloc(sizeof(int*)*2000);
  bool array_ok = true;

  if (!array) array_ok = false;


  for(int i=0; i<2000; i++){
    array[i] = malloc(sizeof(int));
    if(!array[i]) array_ok = false;
  }

  for (int i=0; i<2000; i++){
    *array[i] = i;
  }

  //for (int i=0; i<5; i++) printf("%d -> %d \n",i+1,*(int*)array[i]);
  print_test("Se creo los datos dinamicos", array_ok);

  bool inserto_ok = true;

  for (int i = 0; i < 2000; i++) inserto_ok &= lista_insertar_ultimo(lista,array[i]) && *(int*)lista_ver_ultimo(lista) == i;

  print_test("Se insertaron todos los elementos correctamente",inserto_ok);

  bool borraron_ok = true;

  for (int i = 0; i < 2000; i++){
    int* numero = lista_borrar_primero(lista);
    borraron_ok &= *numero == i;
    free(numero);
  }
  print_test("Se borraron todos los elementos",borraron_ok);
  print_test("La lista tiene que estar vacia",lista_esta_vacia(lista));
  lista_destruir(lista,NULL);
  free(array);
  print_test("lista destruida",true);


}

void pruebas_lista_volumen_destruir_con_elementos_dinamicos(){
  printf("PRUEBAS LISTA DESTRUIR CON ELEMENTOS DINAMICOS \n");

  lista_t* lista = lista_crear();
  print_test("La lista esta creada", lista != NULL);
  print_test("La lista esta vacia", lista_esta_vacia(lista) );

  int** array =malloc(sizeof(int*)*2000);
  bool array_ok = true;

  if (!array) array_ok = false;


  for(int i=0; i<2000; i++){
    array[i] = malloc(sizeof(int));
    if(!array[i]) array_ok = false;
  }

  for (int i=0; i<2000; i++){
    *array[i] = i;
  }

  //for (int i=0; i<5; i++) printf("%d -> %d \n",i+1,*(int*)array[i]);
  print_test("Se creo los datos dinamicos", array_ok);

  bool inserto_ok = true;

  for (int i = 0; i < 2000; i++) inserto_ok &= lista_insertar_ultimo(lista,array[i]) && *(int*)lista_ver_ultimo(lista) == i;

  print_test("Se insertaron todos los elementos correctamente",inserto_ok);

  lista_destruir(lista,free);
  free(array);
  print_test("lista destruida",true);


}

void pruebas_lista_alumno() {
  pruebas_lista_vacia();
  pruebas_lista_insertar_primero_sin_elementos_dinamicos();
  pruebas_lista_insertar_primero_con_elementos_dinamicos();
  pruebas_lista_insertar_ultimo_sin_elementos_dinamicos();
  pruebas_lista_insertar_ultimo_con_elementos_dinamicos();
  pruebas_lista_volumen_sin_elementos_dinamicos();
  pruebas_lista_volumen_con_elementos_dinamicos();
  //pruebas_lista_volumen_destruir_sin_elementos_dinamicos();
  pruebas_lista_volumen_destruir_con_elementos_dinamicos();
}
