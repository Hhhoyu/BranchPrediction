CC = g++
OPT = -O0
WARN = -Wall
#DB	= -g;
CFLAGS = $(OPT) $(WARN) $(INC) $(LIB)

# List all your .cc/.cpp files here (source files, excluding header files)
SIM_SRC = sim.cc Bimodal.cc CountsTable.cc 

# List corresponding compiled object files here (.o files)
SIM_OBJ = sim.o Bimodal.o CountsTable.o 

all: sim
	@echo "my work is done here..."

# rule for making sim
sim: $(SIM_OBJ)
	$(CC) -o sim $(CFLAGS) $(SIM_OBJ) -lm
	@echo "-----------DONE WITH sim-----------"


# generic rule for converting any .cpp file to any .o file
 
.cc.o:
	$(CC) $(CFLAGS)  -c -g $*.cc

.cpp.o:
	$(CC) $(CFLAGS)  -c -g $*.cpp


# type "make clean" to remove all .o files plus the sim binary

clean:
	rm -f *.o sim


# type "make clobber" to remove all .o files (leaves sim binary)

clobber:
	rm -f *.o


