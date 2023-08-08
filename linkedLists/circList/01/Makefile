APPS = ./apps
BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
SRC = ./src
LIB = ./lib

FLAGS = -03
LIBS = -lm -lsd -L ${LIB}

all: libsd myapps

libsd: ${OBJ}/circ_list.o
	ar -rcs ${LIB}/libsd.a ${OBJ}/*.o

myapps: ${BIN}/test_linked_list

${OBJ}/%.o: ${SRC}/%.c ${INCLUDE}/%.h
	gcc -c $< -I ${INCLUDE} -o $@

$(BIN)/%: $(APPS)/%.c
	gcc $< ${LIBS} -I ${INCLUDE} -o $@

run:
	${BIN}/app

clean:
	rm -rf ${BIN}/* ${LIB}/* ${OBJ}/*
