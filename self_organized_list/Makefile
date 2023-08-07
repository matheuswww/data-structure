APPS = ./apps
BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
SRC = ./src
LIB = ./lib

FLAGS = -03
LIBS = -lm -lsd -L ${LIB}

all: libsd myapps

libsd: ${OBJ}/self_organized_linkedList.o
	ar -rcs ${LIB}/libsd.a ${OBJ}/*.o

myapps: ${BIN}/test_self_organized_linkedList

${OBJ}/%.o: ${SRC}/%.c ${INCLUDE}/%.h
	gcc -c $< -I ${INCLUDE} -o $@

$(BIN)/%: $(APPS)/%.c
	gcc $< ${LIBS} -I ${INCLUDE} -o $@

run:
	${BIN}/app

clean:
	rm -rf ${BIN}/* ${LIB}/* ${OBJ}/*
