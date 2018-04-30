EXEC = tail
CC = gcc
CFLAGS = -g -std=c99 -Wall -Wtype-limits -pedantic -Wconversion -Wno-sign-conversion
VFLAGS = --leak-check=full --track-origins=yes --show-reachable=yes
CFILES =  tail.c cola.c

all:
	$(CC) $(CFLAGS) $(CFILES) -o $(EXEC)

run: all
	./$(EXEC)

valgrind: all
	valgrind $(VFLAGS) ./$(EXEC)

tail: all
	./$(EXEC) 4 < t1.txt
