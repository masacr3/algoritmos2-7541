#include "pila.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#include <strings.h>


/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

void pruebas_pila_vacia(){

  printf("PRUEBAS CON PILA VACIA \n");

  pila_t* pila = pila_crear();
  print_test("La pila esta creada", pila != NULL);
  print_test("La pila esta vacia", pila_esta_vacia(pila) );

  print_test("Ver tope es una operacion invalida", !pila_ver_tope(pila));
  print_test("Desapilar es una operacion invalida", !pila_desapilar(pila));

  pila_destruir(pila);
  print_test("pila destruida",true);
}

void pruebas_pila_apilar(){
  printf("\n\nPRUEBAS APILAR\n");
  pila_t* pila = pila_crear();
  int array[] = {1,2,3};
  print_test("La pila esta creada", pila != NULL);
  print_test("La pila esta vacia", pila_esta_vacia(pila) );
  print_test("Apilar 1",pila_apilar(pila,&array[0]));
  print_test("Chequeo que este 1 en tope de la pila", *(int*) pila_ver_tope(pila) == 1);
  print_test("Apilar 2",pila_apilar(pila,&array[1]));
  print_test("Chequeo que este 2 en tope de la pila", *(int*) pila_ver_tope(pila) == 2);
  print_test("Apilar 3",pila_apilar(pila,&array[2]));
  print_test("Chequeo que este 3 en tope de la pila", *(int*) pila_ver_tope(pila) == 3);
  print_test("Apilar NULL es una operacion valida",pila_apilar(pila,NULL));
  print_test("Chequeo que este NULL en tope de la pila", pila_ver_tope(pila) == NULL);

  pila_destruir(pila);
  print_test("pila destruida",true);
}

void pruebas_pila_desapilar(){
  printf("\n\nPRUEBAS DESAPILAR\n");

  pila_t* pila = pila_crear();
  int array[] = {1,2,3};

  print_test("La pila esta creada", pila != NULL);
  print_test("La pila esta vacia", pila_esta_vacia(pila) );

  bool apilar_elementos_ok = true;
  for (int i = 0; i < 3; i++) apilar_elementos_ok &= pila_apilar(pila,&array[i]);

  print_test("Pila cargada con elementos -> [1,2,3]", apilar_elementos_ok);
  print_test("Desapilar 3", *(int*)pila_desapilar(pila) == 3);
  print_test("Desapilar 2", *(int*)pila_desapilar(pila) == 2);
  print_test("Desapilar 1", *(int*)pila_desapilar(pila) == 1);
  print_test("La pila esta vacia no se puede desapilar", !pila_desapilar(pila) );
  pila_destruir(pila);
  print_test("pila destruida",true);
}


void pruebas_pila_volumen(){
  printf("\n\nPRUEBAS DE VOLUMEN PILA\n");

  pila_t* pila = pila_crear();
  print_test("La pila esta creada", pila != NULL);
  print_test("La pila esta vacia", pila_esta_vacia(pila) );

  size_t TAM = 5000;
  int array[TAM];

  for (int i =0 ; i< TAM ; i++) array[i] = i;

  bool apilar_elementos_ok = true;
  for (int i =0 ; i <TAM ; i++) apilar_elementos_ok &= pila_apilar(pila,&array[i]) && *(int*)pila_ver_tope(pila) == array[i];

  print_test("Se apilaron todos los elementos correctamente",apilar_elementos_ok);

  bool desapilar_elementos_ok = true;
  for(int i =0; i<TAM ; i++) desapilar_elementos_ok &= *(int*)pila_desapilar(pila) == array[TAM-1-i];

  print_test("Se desapilaron todos los elementos correctamente",desapilar_elementos_ok);
  print_test("La pila tiene que estar vacia", pila_esta_vacia(pila));
  pila_destruir(pila);
  print_test("pila destruida",true);
}


void pruebas_pila_alumno() {
  pruebas_pila_vacia();
  pruebas_pila_apilar();
  pruebas_pila_desapilar();
  pruebas_pila_volumen();
}
