#This is a Makefile

all:
	gcc -o summation summation.c -lpthread -lm

deb:
	gcc -Wall -g summation.c -lpthread -lm

exec:
	./summation 3 10000

.PHONY: clean
clean:
	rm -f summation a.out
