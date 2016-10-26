# Makefile for app_four

CC=gcc
CFLAGS=-Wall
INCLUDES=-I./include -I./src
LIBS=-lglut -lGLU -lGL -lglew

default: app

app:
	 $(CC) app_four.cpp display.o -o app_four.out $(INCLUDES) $(LIBS)

display:
	$(CC) display.cpp -o display.o $(INCLUDES) $(LIBS)

run:
	./app_four.out
