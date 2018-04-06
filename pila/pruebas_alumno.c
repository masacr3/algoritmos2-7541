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

  //caso borde
  print_test("Ver tope es una operacion invalida", !pila_ver_tope(pila));
  //caso borde
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

  for (int i = 0; i < 3; i++){
    pila_apilar(pila,&array[i]);
  }
  print_test("Pila cargada con elementos -> [1,2,3]",!pila_esta_vacia(pila));

  print_test("Desapilar 3", *(int*)pila_desapilar(pila) == 3);
  print_test("Desapilar 2", *(int*)pila_desapilar(pila) == 2);
  print_test("Desapilar 1", *(int*)pila_desapilar(pila) == 1);
  print_test("La pila esta vacia no se puede desapilar", !pila_desapilar(pila) );

  pila_destruir(pila);
  print_test("pila destruida",true);

}

void prueba_pila_redimensionar(){
  printf("\n\nPRUEBAS REDIMENSIONAR\n");
  pila_t* pila = pila_crear();
  int array[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
  print_test("La pila esta creada", pila != NULL);
  print_test("La pila esta vacia", pila_esta_vacia(pila) );

  for (int i=0; i<10; i++){
    pila_apilar(pila,&array[i]);
  }
  print_test("La pila esta llenada hasta su capacidad maxima = 10",true);
  print_test("redimensiono y apilo 11", pila_apilar(pila,&array[10]));
  print_test("chequeo el tope tiene que ser 11", *(int*)pila_ver_tope(pila) == 11);
  print_test("apilo 12", pila_apilar(pila,&array[11]));
  print_test("chequeo el tope tiene que ser 12", *(int*)pila_ver_tope(pila) == 12);
  print_test("apilo 13", pila_apilar(pila,&array[12]));
  print_test("chequeo el tope tiene que ser 13", *(int*)pila_ver_tope(pila) == 13);

  print_test("Empiezo a desapilar [1,2,3,4,5,6,7,8,9,10,11,12,13]",true);
  for (int i=0; i<13 ; i++)
  {
    printf("desapilando %d",13-i);
    print_test(" ",*(int*) pila_desapilar(pila) == array[12-i]);
  }
  print_test("La pila tiene que estar vacia", pila_esta_vacia(pila));
  pila_destruir(pila);
  print_test("pila destruida",true);

}


void pruebas_pila_alumno() {
  pruebas_pila_vacia();
  pruebas_pila_apilar();
  pruebas_pila_desapilar();
  prueba_pila_redimensionar();
}
