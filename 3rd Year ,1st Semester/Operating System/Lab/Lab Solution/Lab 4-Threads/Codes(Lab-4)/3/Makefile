#This is a Makefile

all:
	gcc -fopenmp -o sum_serial sum_serial.c -lrt

next:
	gcc sum_serial.c -lgomp -o sum_serial.exe	

deb:
	gcc -Wall -g sum_serial.c -lrt

com:
	gcc  -fopenmp -o sum_serial sum_serial.c -lrt

exec:
	./sum_serial

exec1:
	./sum_serial.exe

.PHONY: clean
clean:
	rm -f sum_serial a.out ./sum_serial.exe