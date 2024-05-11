#This is a Makefile

all:
	gcc -o sum_pthread sum_pthread.c -lpthread -lm

deb:
	gcc -Wall -g sum_pthread.c -lpthread -lm

exec:
	./sum_pthread 10 10

.PHONY: clean
clean:
	rm -f sum_pthread a.out
