BINS:= hello hybrid-hello multiple

all: $(BINS)

hello: hello.c
	gcc -o hello -fopenmp hello.c 

hybrid-hello: hybrid-hello.c
	mpicc -openmp -lgomp -fopenmp-o hybrid-hello hybrid-hello.c

multiple: multiple.c
	mpicc -openmp -lgomp -fopenmp-o multiple multiple.c

test: $(BINS)
	@echo "Test OpenMP..."
	@./hello
	@echo "Test MPI..."
	@mpirun -np 4 ./hybrid-hello
	@echo "Test Multiple..."
	@mpirun -np 4 ./multiple

clean:
	@rm -f $(BINS)