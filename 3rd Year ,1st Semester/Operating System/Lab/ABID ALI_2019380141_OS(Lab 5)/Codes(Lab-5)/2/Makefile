#this is a Makefile

all:
	gcc -o buffer buffer.c -lpthread -lm

deb:
	gcc -Wall -g buffer.c -lpthread -lm

exec:
	./buffer 10 10 10

.PHONY: clean
clean:
	rm -f buffer a.out