CC = gcc
CFLAGS = -std=gnu99 -Wall -g #-DDEBUG

EXECS = dlisttest

all: $(EXECS)

dnode.o: dnode.c dnode.h
	$(CC) $(CFLAGS) -c dnode.c -o dnode.o

dlist.o: dlist.c dlist.h dnode.h
	$(CC) $(CLFAGS) -c dlist.c -o dlist.o

dlisttest: dnode.o dlist.o dlisttest.c
	$(CC) $(CFLAGS) dlisttest.c dnode.o dlist.o -o dlisttest

.PHONY: clean
clean:
	/bin/rm -rf $(EXECS) dnode.o dlist.o

