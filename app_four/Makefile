# Makefile for app_four

CC=g++
CFLAGS=-Wall
#INCLUDES=-I./include -I./src
LIBS=-lglut -lGLU -lGL -lSDL2 -lGLEW

default: app

app:
	 $(CC) app_four.cpp display.o -o app_four.out $(LIBS)
	 #$(CC) app_four.cpp -o app_four.out $(INCLUDES) $(LIBS)

display.o:
	$(CC) -c display.cpp -o display.o

run:
	./app_four.out
