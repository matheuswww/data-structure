APPS = ./apps
BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
SRC = ./src

all: libsd myapps

libsd: ${OBJ}/float_vector.o

myapps: ${BIN}/app

${OBJ}/%.o: ${SRC}/%.c ${INCLUDE}/%.h
	gcc -c $< -I ${INCLUDE} -o $@

$(BIN)/%: $(APPS)/%.c
	gcc $< ${OBJ}/*.o -I ${INCLUDE} -o $@

run:
	${BIN}/app

clean:
	rm -rf ${BIN}/* ./obj/*
