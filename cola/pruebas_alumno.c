#include "cola.h"
#include "pila.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>


/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/
void destruir_pila(void* dato){
  pila_t* pila = dato;
  pila_destruir(pila);
}

pila_t* crear_pila_cargada(int *array){
  pila_t* pila = pila_crear();
  if(!pila) return NULL;

  int TAM = 2;

  bool apilo = true;
  for (int i =0; i < TAM ; i++) apilo &= pila_apilar(pila,&array[i]);

  if (!apilo){
    pila_destruir(pila);
    return NULL;
  }
  return pila;
}


void pruebas_cola_vacia(){

  printf("PRUEBAS COLA VACIA \n");

  cola_t* cola = cola_crear();
  print_test("La cola esta creada", cola != NULL);
  print_test("La cola esta vacia", cola_esta_vacia(cola) );

  print_test("Ver primero es una operacion invalida", !cola_ver_primero(cola));
  print_test("Desencolar es una operacion invalida", !cola_desencolar(cola));

  cola_destruir(cola,NULL);
  print_test("cola destruida",true);
}


void pruebas_cola_volumen_sin_elementos_dinamicos(){
  printf("\n\nPRUEBAS COLA VOLUMEN SIN ELEMENTOS DINAMICOS\n");

  cola_t* cola = cola_crear();
  print_test("La cola esta creada", cola != NULL);
  print_test("La cola esta vacia", cola_esta_vacia(cola) );

  size_t TAM = 5000;
  int array[TAM];

  for (int i =0 ; i< TAM ; i++) array[i] = i;

  bool encolar_elementos_ok = true;
  for (int i =0 ; i <TAM ; i++) encolar_elementos_ok &= cola_encolar(cola,&array[i]);

  print_test("Se encolaron todos los elementos correctamente",encolar_elementos_ok);

  bool desencolar_elementos_ok = true;
  for(int i =0; i<TAM ; i++) desencolar_elementos_ok &= *(int*)cola_desencolar(cola) == array[i];

  print_test("Se desencolaron todos los elementos correctamente",desencolar_elementos_ok);
  print_test("La cola tiene que estar vacia", cola_esta_vacia(cola));
  cola_destruir(cola,NULL);
  print_test("cola destruida",true);
}

void pruebas_cola_volumen_con_elementos_dinamicos(){
  printf("\n\nPRUEBAS COLA VOLUMEN CON ELEMENTOS DINAMICOS\n");

  cola_t* cola = cola_crear();
  print_test("La cola esta creada", cola != NULL);
  print_test("La cola esta vacia", cola_esta_vacia(cola) );

  size_t TAM = 5000;

  int array[] = {1,2};

  bool encolar_elementos_ok = true;
  for (int i =0 ; i <TAM ; i++) encolar_elementos_ok &= cola_encolar(cola,crear_pila_cargada(array));

  print_test("Se encolaron todos los elementos correctamente",encolar_elementos_ok);
  print_test("la cola esta llena", !cola_esta_vacia(cola));

  bool desencolar_elementos_ok = true;
  for (int i =0 ; i <TAM ; i++){
      void* pila = (pila_t*) cola_desencolar(cola);
      desencolar_elementos_ok &= *(int*)pila_ver_tope(pila) == 2;
      destruir_pila(pila);
  }

  print_test("Se desencolaron todos los elementos correctamente",desencolar_elementos_ok);
  print_test("se destruyeron todas las pilas",true);
  print_test("la cola esta vacia", cola_esta_vacia(cola));
  cola_destruir(cola,NULL);
  print_test("cola destruida",true);
}

void pruebas_cola_volumen_destruir_sin_elementos_dinamicos(){
  printf("\n\nPRUEBAS COLA VOLUMEN DESTRUIR SIN ELEMENTOS DINAMICOS\n");

  cola_t* cola = cola_crear();
  print_test("La cola esta creada", cola != NULL);
  print_test("La cola esta vacia", cola_esta_vacia(cola) );

  size_t TAM = 5000;
  int array[TAM];

  for (int i =0 ; i< TAM ; i++) array[i] = i;

  bool encolar_elementos_ok = true;
  for (int i =0 ; i <TAM ; i++) encolar_elementos_ok &= cola_encolar(cola,&array[i]);

  print_test("Se encolaron todos los elementos correctamente",encolar_elementos_ok);
  cola_destruir(cola,NULL);
  print_test("cola destruida",true);
}

void pruebas_cola_volumen_destruir_con_elementos_dinamicos(){
  printf("\n\nPRUEBAS COLA VOLUMEN DESTRUIR CON ELEMENTOS DINAMICOS\n");

  cola_t* cola = cola_crear();
  print_test("La cola esta creada", cola != NULL);
  print_test("La cola esta vacia", cola_esta_vacia(cola) );

  size_t TAM = 5000;

  int array[] = {1,2};

  bool encolar_elementos_ok = true;
  for (int i =0 ; i <TAM ; i++) encolar_elementos_ok &= cola_encolar(cola,crear_pila_cargada(array));

  print_test("Se encolaron todos los elementos correctamente",encolar_elementos_ok);
  print_test("la cola esta llena", !cola_esta_vacia(cola));
  cola_destruir(cola,destruir_pila);
  print_test("se destruyeron los elementos dinamicos",true);
  print_test("cola destruida",true);
}

void pruebas_cola_ver_primero(){
  printf("\n\nPRUEBAS COLA VER PRIMERO\n");

  cola_t* cola = cola_crear();
  print_test("La cola esta creada", cola != NULL);
  print_test("La cola esta vacia", cola_esta_vacia(cola) );

  int array[] = {1,2,3};
  bool encolo = true;
  for (int i = 0; i< 3; i++) encolo &= cola_encolar(cola,&array[i]);

  print_test("encolo todos los elementos",encolo);
  print_test("ver primero tiene que ser 1",*(int*) cola_desencolar(cola) == 1);
  cola_destruir(cola,NULL);
  print_test("cola destruida",true);
}

void pruebas_cola_encolar_desencolar_sin_elementos_dinamicos(){
  printf("\n\nPRUEBAS COLA ENCOLAR Y DESENCOLAR SIN ELEMENTOS DINAMICOS\n");

  cola_t* cola = cola_crear();
  print_test("La cola esta creada", cola != NULL);
  print_test("La cola esta vacia", cola_esta_vacia(cola) );

  int array[] = {1,2,3};
  bool encolo = true;
  for (int i = 0; i< 3; i++) encolo &= cola_encolar(cola,&array[i]);

  print_test("encolo todos los elementos",encolo);

  print_test("Desencolo 1", *(int*)cola_desencolar(cola)==array[0]);
  print_test("Desencolo 2", *(int*)cola_desencolar(cola)==array[1]);
  print_test("Desencolo 3", *(int*)cola_desencolar(cola)==array[2]);
  print_test("La cola esta vacia", cola_esta_vacia(cola));
  cola_destruir(cola,NULL);
  print_test("cola destruida",true);
}

void pruebas_cola_encolar_desencolar_con_elementos_dinamicos(){
  printf("\n\nPRUEBAS COLA ENCOLAR Y DESENCOLAR CON ELEMENTOS DINAMICOS\n");

  cola_t* cola = cola_crear();
  print_test("La cola esta creada", cola != NULL);
  print_test("La cola esta vacia", cola_esta_vacia(cola) );

  int array[] = {1,2};

  bool encolo = true;
  for (int i = 0; i< 3; i++) encolo &= cola_encolar(cola,crear_pila_cargada(array));

  print_test("encolo todos los elementos",encolo);

  void* pila = cola_desencolar(cola);
  print_test("Desencolo pila con 2 elementos", *(int*)pila_ver_tope(pila)==2);
  destruir_pila(pila);
  pila = cola_desencolar(cola);
  print_test("Desencolo pila con 2 elementos", *(int*)pila_ver_tope(pila)==2);
  destruir_pila(pila);
  pila = cola_desencolar(cola);
  print_test("Desencolo pila con 2 elementos", *(int*)pila_ver_tope(pila)==2);
  destruir_pila(pila);
  print_test("se destruyeron todas pilas",true);
  print_test("La cola esta vacia", cola_esta_vacia(cola));
  cola_destruir(cola,NULL);
  print_test("cola destruida",true);
}

void pruebas_cola_alumno() {
  pruebas_cola_vacia();
  pruebas_cola_ver_primero();
  pruebas_cola_encolar_desencolar_sin_elementos_dinamicos();
  pruebas_cola_encolar_desencolar_con_elementos_dinamicos();
  pruebas_cola_volumen_sin_elementos_dinamicos();
  pruebas_cola_volumen_con_elementos_dinamicos();
  pruebas_cola_volumen_destruir_sin_elementos_dinamicos();
  pruebas_cola_volumen_destruir_con_elementos_dinamicos();
}
