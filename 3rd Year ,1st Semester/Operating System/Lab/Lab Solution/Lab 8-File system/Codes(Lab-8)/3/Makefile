CC = gcc -I ./include
CFLAGS = -std=gnu99 -Wall -g #-DDEBUG

INC = ./include
SRC = ./src
OBJ = ./obj
BIN = ./bin

vpath %.h ./include
vpath %.c ./src
vpath %.o ./obj

EXECS = file_stat read_dir fdump  sender receiver traverse

all: $(EXECS)

$(OBJ)/file_stat.o: file_stat.c
	$(CC) $(CFLAGS) -c $(SRC)/file_stat.c -o $(OBJ)/file_stat.o

file_stat: $(SRC)/file_stat.c $(OBJ)/file_stat.o
	$(CC) $(CFLAGS) -o $(BIN)/file_stat $(OBJ)/file_stat.o

$(OBJ)/read_dir.o: read_dir.h read_dir.c
	$(CC) $(CFLAGS) -c $(SRC)/read_dir.c -o $(OBJ)/read_dir.o

read_dir: $(SRC)/read_dir.c $(OBJ)/read_dir.o
	$(CC) $(CFLAGS) -o $(BIN)/read_dir $(OBJ)/file_stat.o

$(OBJ)/hexdump.o: hexdump.h hexdump.c
	$(CC) $(CFLAGS) -c $(SRC)/hexdump.c -o $(OBJ)/hexdump.o

fdump: $(SRC)/fdump.c $(OBJ)/hexdump.o
	$(CC) $(CFLAGS) $(OBJ)/hexdump.o $(SRC)/fdump.c -o $(OBJ)/fdump -o $(BIN)/fdump

sender: $(SRC)/sender.c
	$(CC) $(CFLAGS) -pthread $(SRC)/sender.c -o $(BIN)/sender

receiver: receiver.c
	$(CC) $(CFLAGS) -pthread $(SRC)/receiver.c -o $(BIN)/receiver

$(OBJ)/traverse.o: traverse.c 
	$(CC) $(CFLAGS) -c $(SRC)/traverse.c -o $(OBJ)/traverse.o

traverse: $(SRC)/traverse.c $(OBJ)/traverse.o
	$(CC) $(CFLAGS) -o $(BIN)/traverse $(OBJ)/traverse.o
.PHONY: clean
clean:
	/bin/rm -rf $(BIN)/* $(OBJ)/* core* *~
