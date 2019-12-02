all: obj/main.o
	gcc -g -o cubes obj/main.o -lglfw

clean:
	rm -rf cubes
	rm obj/*

obj/main.o: src/main.c
	gcc -g -c -o obj/main.o src/main.c
