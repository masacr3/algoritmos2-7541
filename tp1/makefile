EXEC = pruebas_sp
CC = gcc
CFLAGS = -g -std=c99 -Wall -Wtype-limits -pedantic -Wconversion -Wno-sign-conversion
VFLAGS = --leak-check=full --track-origins=yes --show-reachable=yes
CFILES =  strutil.c pruebas.c

all:
	$(CC) $(CFLAGS) $(CFILES) -o $(EXEC)

run: all
	./$(EXEC)

valgrind: all
	valgrind $(VFLAGS) ./$(EXEC)
