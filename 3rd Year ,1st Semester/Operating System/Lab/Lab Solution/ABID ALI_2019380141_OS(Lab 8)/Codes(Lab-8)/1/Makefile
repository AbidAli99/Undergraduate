CC = gcc -I ./include
CFLAGS = -std=gnu99 -Wall -g #-DDEBUG

INC = ./include
SRC = ./src
OBJ = ./obj
DOC = ./doc
BIN = ./bin

vpath %.h ./include
vpath %.c ./src
vpath %.o ./obj

EXECS = fdump

all: $(EXECS)

$(OBJ)/hexdump.o: hexdump.h hexdump.c
	$(CC) $(CFLAGS) -c $(SRC)/hexdump.c -o $(OBJ)/hexdump.o

fdump: $(SRC)/fdump.c $(OBJ)/hexdump.o
	$(CC) $(CFLAGS) $(OBJ)/hexdump.o $(SRC)/fdump.c -o $(OBJ)/fdump -o $(BIN)/fdump

.PHONY: clean
clean:
	/bin/rm -rf $(BIN)/* $(OBJ)/* core* *~
