CC = gcc
CFLAGS = -c -Wall -Werror -o
ADD = -I thirdparty -I src
OBJECTS = build/main.o build/function.o build/menu.o
OBJECTS_T = build/main_t.o build/function-test.o

all :  prog

prog : $(OBJECTS) bin/
	$(CC) $(OBJECTS) -o bin/Game
test: $(OBJECTS_T) bin/
	$(CC) $(OBJECTS_T) -o bin/Test
	./bin/Test
build/main.o : build/ src/main.c
	$(CC) src/main.c $(CFLAGS) build/main.o
build/function.o : build/ src/function.c
	$(CC) src/function.c $(CFLAGS) build/function.o
build/menu.o : build/ src/menu.c
	$(CC) src/menu.c $(CFLAGS) build/menu.o
build/main_t.o : build/ test/main.c
	$(CC) $(ADD) test/main.c $(CFLAGS) build/main_t.o
build/function-test.o : build/ test/function-test.c
	$(CC) $(ADD) test/function-test.c $(CFLAGS) build/function-test.o
bin/ :
	mkdir bin
build/ :
	mkdir build

.PHONY : clean
clean : 
	rm -f bin/* build/*
game :
	./bin/Game
open :
	gedit src/main.c src/function.h src/function.c src/menu.c
open-test:
	gedit test/main.c test/function-test.c
