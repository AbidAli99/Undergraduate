#This is a Makefile

all:
	gcc -o name_pipe_read_write name_pipe_read_write.c

deb:
	gcc -Wall -g name_pipe_read_write.c

com:
	gcc name_pipe_read_write.c -lrt

exec:
	./name_pipe_read_write

out:
	./a.out

.PHONY: clean
clean:
	rm -f name_pipe_read_write a.out
