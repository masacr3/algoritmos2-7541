EXEC = join
CC = gcc
CFLAGS = -g -std=c99 -Wall -Wtype-limits -pedantic -Wconversion -Wno-sign-conversion
VFLAGS = --leak-check=full --track-origins=yes --show-reachable=yes
CFILES =  strutil.c pruebas_join.c

all:
	$(CC) $(CFLAGS) $(CFILES) -o $(EXEC)

run: all
	./$(EXEC)

valgrind: all
	valgrind $(VFLAGS) ./$(EXEC)

tail: all
	./$(EXEC) 4 < t1.txt

syntax_val: all
	cat pruebas_sv.txt
	./$(EXEC) < pruebas_sv.txt
