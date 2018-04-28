EXEC = diff
CC = gcc
CFLAGS = -g -std=c99 -Wall -Wtype-limits -pedantic -Wconversion -Wno-sign-conversion
VFLAGS = --leak-check=full --track-origins=yes --show-reachable=yes
CFILES =  diff.c

all:
	$(CC) $(CFLAGS) $(CFILES) -o $(EXEC)

run: all
	cat t1.txt
	./$(EXEC) t1.txt t2.txt

valgrind: all
	valgrind $(VFLAGS) ./$(EXEC)
