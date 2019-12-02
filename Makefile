all: obj/main.o
	gcc -g -o cubes obj/main.o

obj/main.o: src/main.c
	gcc -g -c -o obj/main.o src/main.c
