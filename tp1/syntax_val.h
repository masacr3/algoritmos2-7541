#ifndef SYNTAX_VAL_H
#define SYNTAX_VAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"
#include <stdbool.h>


/*
 *
 * emula 'in' de python
 *
 */
bool in(char c, char* str);

/*
 *  Retorna caracter opuesto a 'c'
 *  Pre: c in '{(['
 *  Post: devuelve un char
 */
char char_opuesto(char c);


/*
 * Verifica si el script esta balanceado
 * Pre: No toma encuenta en el balanceo string alphanumericos
 *      ni caractes encerrados en ''
 * Post: devuelve true si esta balanceado en caso contrario false
 */
bool value_syntax(char* str);

#endif // SYNTAX_VAL_H

