CC = gcc
CFLAGS = -c -Wall -Werror -o
OBJECTS = build/main.o

all:  prog
prog: $(OBJECTS) bin/
	$(CC) $(OBJECTS) -o bin/Game
build/main.o : build/ src/main.c
	$(CC) src/main.c $(CFLAGS) build/main.o
bin/ :
	mkdir bin
build/ :
	mkdir build

.PHONY : clean
clean: 
	rm -f bin/* build/*
