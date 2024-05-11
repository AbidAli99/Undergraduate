CC = gcc -I ./include
CFLAGS = -std=gnu99 -Wall -g #-DDEBUG

INC = ./include
SRC = ./src
OBJ = ./obj
BIN = ./bin

vpath %.h ./include
vpath %.c ./src
vpath %.o ./obj

EXECS = file_stat

all: $(EXECS)

$(OBJ)/file_stat.o: file_stat.c
	$(CC) $(CFLAGS) -c $(SRC)/file_stat.c -o $(OBJ)/file_stat.o

file_stat: $(SRC)/file_stat.c $(OBJ)/file_stat.o
	$(CC) $(CFLAGS) -o $(BIN)/file_stat $(OBJ)/file_stat.o

.PHONY: clean
clean:
	/bin/rm -rf $(BIN)/* $(OBJ)/* core* *~
