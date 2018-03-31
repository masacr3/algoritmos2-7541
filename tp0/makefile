EXEC = pruebas
CC = gcc
CFLAGS = -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror
VFLAGS = --leak-check=full --track-origins=yes --show-reachable=yes
CFILES = testing.c tp0_pruebas.c tp0.c

all:
	$(CC) $(CFLAGS) $(CFILES) -o $(EXEC)

run: all
	./$(EXEC)

valgrind: all
	valgrind $(VFLAGS) ./$(EXEC)
