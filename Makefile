CC = gcc
CFLAGS = -c -Wall -Werror -o
OBJECTS = build/main.o build/function.o

all:  prog
prog: $(OBJECTS) bin/
	$(CC) $(OBJECTS) -o bin/Game
build/main.o : build/ src/main.c
	$(CC) src/main.c $(CFLAGS) build/main.o
build/function.o : build/ src/function.c
	$(CC) src/function.c $(CFLAGS) build/function.o
bin/ :
	mkdir bin
build/ :
	mkdir build

.PHONY : clean
clean: 
	rm -f bin/* build/*
