#include "lista.h"
#include "testing.h"
#include <stddef.h>
#include <stdlib.h>
#include <strings.h>
#include <stdio.h>

void pruebas_cola_alumno() {
  pruebas_lista_vacia();
  pruebas_lista_ver_primero();
  pruebas_lista_ver_ultimo();
  pruebas_lista_insertar_primero_sin_elementos_dinamicos();
  pruebas_lista_insertar_primero_con_elementos_dinamicos();
  pruebas_lista_insertar_ultimo_sin_elementos_dinamicos();
  pruebas_lista_insertar_ultimo_con_elementos_dinamicos();
  pruebas_lista_volumen_sin_elementos_dinamicos();
  pruebas_lista_volumen_con_elementos_dinamicos();
  pruebas_lista_volumen_destruir_sin_elementos_dinamicos();
  pruebas_lista_volumen_destruir_con_elementos_dinamicos();
}
