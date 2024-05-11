CC = gcc

#.c source code
SRC=$(wildcard ./src/*.c)

#.h header file
HEADER_PATH = -I./include/

#.o object files
OBJS=$(SRC:%.c=%.o)

CFLAG = -g

TARGETS = mem_sim

all : $(TARGETS)

# link to executeable target
$(TARGETS):${OBJS}
	$(CC) $^ -o $@

# compile to generate objs
$(OBJS):%.o : %.c
	${CC} -c ${CFLAG} $< -o $@ $(HEADER_PATH)

clean :
	rm -rf $(TARGETS) $(OBJS) 