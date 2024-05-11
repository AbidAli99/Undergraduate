CC=gcc
CFLAGS= -g

all: consumer producer pipe_test name_pipe_write_read name_pipe_read_write

consumer: shm-posix-consumer.c
	$(CC) $(CFLAGS) -o consumer shm-posix-consumer.c -lrt

producer: shm-posix-producer.c
	$(CC) $(CFLAGS) -o producer shm-posix-producer.c -lrt

pipe_test: pipe_test.c
	$(CC) $(CFLAGS) -o pipe_test pipe_test.c -lrt

name_pipe_write_read: name_pipe_write_read.c
	$(CC) $(CFLAGS) -o name_pipe_write_read name_pipe_write_read.c -lrt

name_pipe_read_write: name_pipe_read_write.c
	$(CC) $(CFLAGS) -o name_pipe_read_write name_pipe_read_write.c -lrt
	
.PHONY: clean

clean:
	rm -f consumer producer pipe_test name_pipe_write_read name_pipe_read_write
