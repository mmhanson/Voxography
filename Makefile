#
# Makefile for the Cubes project.
# Written by Max Hanson, February 2020
#

# variables ====================================================================
CC = gcc
CFLAGS = -Wall --std=c99
LIBS = -lglfw -lGLEW -lGL -lm
TARGET = cubes
# ==============================================================================

# target =======================================================================
all: $(TARGET)

$(TARGET): obj/main.o obj/matrix.o obj/util.o obj/lodepng.o
	$(CC) $(CFLAGS) -o $(TARGET) obj/main.o obj/matrix.o obj/util.o \
	./obj/lodepng.o $(LIBS)

obj/main.o: ./src/main.c
	$(CC) $(CFLAGS) -o ./obj/main.o -c ./src/main.c

obj/matrix.o: ./src/matrix.c
	$(CC) $(CFLAGS) -o ./obj/matrix.o -c ./src/matrix.c

obj/util.o: ./src/util.c
	$(CC) $(CFLAGS) -o ./obj/util.o -c ./src/util.c

obj/lodepng.o: ./deps/lodepng/lodepng.c
	$(CC) $(CFLAGS) -o ./obj/lodepng.o -c ./deps/lodepng/lodepng.c
# ==============================================================================

# clean ========================================================================
clean:
	rm -rf ./obj/*
	rm -rf ./cubes
# ==============================================================================
