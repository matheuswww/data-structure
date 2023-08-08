APPS = ./apps
BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
SRC = ./src
LIB = ./lib

FLAGS = -03
LIBS = -lm -lsd -L ${LIB}

all: libsd myapps

libsd: ${OBJ}/dynamic_stack.o ${OBJ}/double_linked_list.o
	ar -rcs ${LIB}/libsd.a ${OBJ}/*.o

myapps: ${BIN}/test_dynamic_stack

${OBJ}/%.o: ${SRC}/%.c ${INCLUDE}/%.h
	gcc -c $< -I ${INCLUDE} -o $@

$(BIN)/%: $(APPS)/%.c
	gcc $< ${LIBS} -I ${INCLUDE} -o $@

run:
	${BIN}/app

clean:
	rm -rf ${BIN}/* ${LIB}/* ${OBJ}/*
