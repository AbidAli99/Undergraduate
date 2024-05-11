#This is a makefile

all:
	gcc -o shm-posix-consumer shm-posix-consumer.c -lrt

deb:
	gcc -Wall -g shm-posix-consumer.c -lrt

com:
	gcc -o shm-posix-consumer shm-posix-consumer.c -lrt

exec:
	./shm-posix-consumer

out:
	./a.out
	
.PHONY: clean
clean:
	rm -f shm-posix-consumer a.out