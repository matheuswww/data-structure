APPS = apps
BIN = bin
INCLUDE = include
OBJ = obj
SRC = src

all: libsd myapps

libsd: \
	${OBJ}/float_vector.o

myapps: 
	gcc ./${APPS}/app.c ./${OBJ}/float_vector.o -I ./${INCLUDE} -o ./${BIN}/app

./${OBJ}/%.o: ./${SRC}/%.c ./${INCLUDE}/%.h
	gcc -c $< -I ./${INCLUDE} -o $@

run:
	./${BIN}/app

clean:
	rm ./${BIN}/* ./obj/*
