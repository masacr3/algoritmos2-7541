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

void pruebas_lista_volumen_destruir_sin_elementos_dinamicos(){
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
  lista_destruir(lista,NULL);
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

  print_test("Se creo los datos dinamicos", array_ok);

  bool inserto_ok = true;

  for (int i = 0; i < 2000; i++) inserto_ok &= lista_insertar_ultimo(lista,array[i]) && *(int*)lista_ver_ultimo(lista) == i;

  print_test("Se insertaron todos los elementos correctamente",inserto_ok);

  lista_destruir(lista,free);
  free(array);
  print_test("lista destruida",true);


}

/* Pruebas iterador */

void pruebas_iterador_lista_vacia(){
  printf("PRUEBAS ITERADOR LISTA VACIA \n");

  lista_t* lista = lista_crear();

  bool ok = true;

  ok &= lista != NULL && lista_esta_vacia(lista);

  print_test("La lista se creo",ok);

  lista_iter_t* iter = lista_iter_crear(lista);
  print_test("El iterador esta creado y apunta al principio de la lista", lista != NULL);
  print_test("Avanzar es invalido", !lista_iter_avanzar(iter));
  print_test("Borrar actual es invalido", !lista_iter_borrar(iter));
  print_test("Ver actual es invalido", !lista_iter_ver_actual(iter));
  print_test("Esta al final es valido", lista_iter_al_final(iter));
  lista_iter_destruir(iter);
  lista_destruir(lista,NULL);
  print_test("Se eliminaron la lista y el iterador",true);
}

void pruebas_iterador_insertar(){
  printf("PRUEBAS ITERADOR INSERTAR \n");

  lista_t* lista = lista_crear();

  bool ok = true;

  ok &= lista != NULL && lista_esta_vacia(lista);

  int lista_original[] = {1,2,3};
  int datos[] = {10,4,5};
  int lista_modificada[] = {10,1,4,2,3,5};

  for(int i=0; i<3 ; i++) ok &= lista_insertar_ultimo(lista,&lista_original[i]);

  print_test("La lista se creo",ok);

  lista_iter_t* iter = lista_iter_crear(lista);
  print_test("El iterador esta creado y apunta al principio de la lista", lista != NULL);
  print_test("Inserto un dato en la posicion actual", lista_iter_insertar(iter,&datos[0]) && *(int*)lista_iter_ver_actual(iter) == datos[0] );
  print_test("Avanzar ", lista_iter_avanzar(iter) && lista_iter_avanzar(iter));
  print_test("Inserto un dato en la posicion actual", lista_iter_insertar(iter,&datos[1]) && *(int*)lista_iter_ver_actual(iter) == datos[1]);

  while(!lista_iter_al_final(iter)) lista_iter_avanzar(iter);

  print_test("Esta al final de la lista", lista_iter_al_final(iter));
  print_test("Inserto un dato en la posicion actual",lista_iter_insertar(iter,&datos[2]) && *(int*)lista_iter_ver_actual(iter) == datos[2]);


  lista_iter_t* iter2 = lista_iter_crear(lista);

  int i = 0;
  while(!lista_iter_al_final(iter2)) {
    ok &= *(int*)lista_iter_ver_actual(iter2) == lista_modificada[i];
    i++;
    lista_iter_avanzar(iter2);
  }



  print_test("Se insertaron todos los datos correctamente",ok);
  lista_iter_destruir(iter);
  lista_iter_destruir(iter2);
  lista_destruir(lista,NULL);
  print_test("Se eliminaron la lista y el iterador",true);
}

void pruebas_lista_alumno() {
  pruebas_lista_vacia();
  pruebas_lista_insertar_primero_sin_elementos_dinamicos();
  pruebas_lista_insertar_primero_con_elementos_dinamicos();
  pruebas_lista_insertar_ultimo_sin_elementos_dinamicos();
  pruebas_lista_insertar_ultimo_con_elementos_dinamicos();
  pruebas_lista_volumen_sin_elementos_dinamicos();
  pruebas_lista_volumen_con_elementos_dinamicos();
  pruebas_lista_volumen_destruir_sin_elementos_dinamicos();
  pruebas_lista_volumen_destruir_con_elementos_dinamicos();
  //iterador
  pruebas_iterador_lista_vacia();
  pruebas_iterador_insertar();
}
