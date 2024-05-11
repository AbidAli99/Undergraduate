#This is a Makefile

all:
	gcc -o name_pipe_write_read name_pipe_write_read.c

deb:
	gcc -Wall -g name_pipe_write_read.c

com:
	gcc name_pipe_write_read.c -lrt

exec:
	./name_pipe_write_read

out:
	./a.out
.PHONY: clean
clean:
	rm -f name_pipe_write_read a.out
