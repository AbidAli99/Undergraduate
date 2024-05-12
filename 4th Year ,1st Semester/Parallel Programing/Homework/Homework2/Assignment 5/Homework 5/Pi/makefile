#
#  USAGE:
#     make          ... to build the program
#     make test     ... to run the default test case
#
# for g++ compiler on Linux
# Note: untested  

CC          = g++
CLINKER     = $(CC)
FLINKER     = $(FC)
OPTFLAGS    = -fopenmp -O0 
LIBS        = -lm
PRE         = ./

FFLAGS	  = $(OPTFLAGS)

CFLAGS	  = $(OPTFLAGS)

OBJ=o
EXE=
RM=rm

EXES=pi_spmd_simple$(EXE) pi_spmd_simple_padded$(EXE) \
     pi_spmd_final$(EXE) pi_loop$(EXE) pi_task$(EXE)  

all: $(EXES)

pi_spmd_simple$(EXE): pi_spmd_simple.$(OBJ) 
	$(CLINKER) $(OPTFLAGS) -o pi_spmd_simple$(EXE) pi_spmd_simple.$(OBJ) $(LIBS)

pi_spmd_simple_padded$(EXE): pi_spmd_simple_padded.$(OBJ) 
	$(CLINKER) $(OPTFLAGS) -o pi_spmd_simple_padded$(EXE) pi_spmd_simple_padded.$(OBJ) $(LIBS)

pi_spmd_final$(EXE): pi_spmd_final.$(OBJ) 
	$(CLINKER) $(OPTFLAGS) -o pi_spmd_final$(EXE) pi_spmd_final.$(OBJ) $(LIBS)

pi_loop$(EXE): pi_loop.$(OBJ) 
	$(CLINKER) $(OPTFLAGS) -o pi_loop$(EXE) pi_loop.$(OBJ) $(LIBS)

pi_vec$(EXE): pi_vec.$(OBJ) 
	$(CLINKER) $(OPTFLAGS) -o pi_vec$(EXE) pi_vec.$(OBJ) $(LIBS)

pi_task$(EXE): pi_task.$(OBJ) 
	$(CLINKER) $(OPTFLAGS) -o pi_task$(EXE) pi_task.$(OBJ) $(LIBS)

test: $(EXES)
	$(PRE)pi_spmd_simple$(EXE) 
	$(PRE)pi_spmd_simple_padded$(EXE) 
	$(PRE)pi_spmd_final$(EXE) 
	$(PRE)pi_loop$(EXE)  
	$(PRE)pi_task$(EXE)  

clean:
	$(RM) $(EXES) *.$(OBJ)

.SUFFIXES:
.SUFFIXES: .c .cpp  .$(OBJ)

.c.$(OBJ):
	$(CC) $(CFLAGS) -c $<

.cpp.$(OBJ):
	$(CC) $(CFLAGS) -c $<
