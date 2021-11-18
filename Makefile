CC = g++
OPT = -O3
WARN = -Wall
CFLAGS = $(OPT) $(WARN) $(INC) $(LIB)
SIM_SRC = sim.cc Bimodal.cc CountsTable.cc BranchHis.cc GShare.cc Smith.cc
SIM_OBJ = sim.o Bimodal.o CountsTable.o BranchHis.o GShare.o Smith.o
all: sim
sim: $(SIM_OBJ)
	$(CC) -o sim $(CFLAGS) $(SIM_OBJ) -lm
.cc.o:
	$(CC) $(CFLAGS)  -c -g $*.cc
clean:
	rm -f *.o sim



