CFLAGS = -g -std=c99 -Wall -Wtype-limits -pedantic -Wconversion -Wno-sign-conversion

tail: tail.c cola.o
diff: diff.c
syntax_val: syntax_val.c pila.o
