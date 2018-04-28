EXEC = tail
CC = gcc
CFLAGS = -g -std=c99 -Wall -Wtype-limits -pedantic -Wconversion -Wno-sign-conversion
VFLAGS = --leak-check=full --track-origins=yes --show-reachable=yes
CFILES =  tail.c

all:
	$(CC) $(CFLAGS) $(CFILES) -o $(EXEC)

run: all
	cat t1.txt
	./$(EXEC) 3 < t1.txt

valgrind: all
	valgrind $(VFLAGS) ./$(EXEC)
