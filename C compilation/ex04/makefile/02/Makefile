APPS = apps
BIN = bin
INCLUDE = include
OBJ = obj
SRC = src

all: libsd myapps

libsd:
	gcc -c ./${SRC}/float_vector.c -I ./${INCLUDE} -o ./${OBJ}/float_vector.o

myapps: 
	gcc ./${APPS}/app.c ./${OBJ}/float_vector.o -I ./${INCLUDE} -o ./${BIN}/app

run:
	./${BIN}/app

clean:
	rm ./${BIN}/* ./obj/*  
