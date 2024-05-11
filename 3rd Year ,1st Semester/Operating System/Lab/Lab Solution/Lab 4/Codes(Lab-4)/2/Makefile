#This is a Makefile

all:
	gcc -o multithread multithread.c -lpthread

deb:
	gcc -Wall -g multithread.c -lpthread

exec:
	./multithread

.PHONY: clean
clean:
	rm -f multithread a.out
