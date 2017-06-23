CC = gcc
CFLAGS = -c -Wall -Werror -o
OBJECTS = build/main.o build/function.o build/menu.o

all:  prog
prog: $(OBJECTS) bin/
	$(CC) $(OBJECTS) -o bin/Game
build/main.o : build/ src/main.c
	$(CC) src/main.c $(CFLAGS) build/main.o
build/function.o : build/ src/function.c
	$(CC) src/function.c $(CFLAGS) build/function.o
build/menu.o : build/ src/menu.c
	$(CC) src/menu.c $(CFLAGS) build/menu.o
bin/ :
	mkdir bin
build/ :
	mkdir build

.PHONY : clean
clean: 
	rm -f bin/* build/*
game :
	./bin/Game
open :
	gedit src/main.c src/function.h src/function.c src/menu.c
