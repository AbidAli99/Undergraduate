#This is a makefile

all:
	gcc -o shm-posix-producer shm-posix-producer.c -lrt

deb:
	gcc -Wall -g shm-posix-producer.c -lrt

com:
	gcc -o shm-posix-producer shm-posix-producer.c -lrt

exec:
	./shm-posix-producer

out:
	./a.out

.PHONY: clean
clean:
	rm -f shm-posix-producer a.out
