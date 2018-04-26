/*
 * Leonel R.
 */

#include <stdlib.h>
#include <string.h>

char* slice(const char* str, size_t inicio, size_t fin);

/*
 * Devuelve las posiciones donde esta SEP
 * posiciones[0] guarda el tamaño del array
 * posiciones[>0] se guardan las posiciones relativas de SEP
 * Post:
 *   >   si no hay coincidencias posiciones[0] = 0
 *   >   si hay coincidencias posiciones[0] = coincidencias , len(posiciones) = coincidencias
 */
int* buscar_sep(const char* str, char sep);

char** split(const char* str, char sep);

void free_strv(char* strv[]);
