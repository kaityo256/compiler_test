all: gcc.out icpc.out
SRC=$(shell ls *.cpp)
OBJ=$(SRC:.cpp=.o)

asm: gcc.s icpc.s

GCCFLAGS=-O3 -march=native -Wall -Wextra -std=c++11 
ICPCFLAGS=-O3 -xHOST -Wall -Wextra -std=c++11 

-include makefile.opt

gcc.out: $(SRC)
	g++ $(GCCFLAGS) $^ -o $@

gcc.s: $(SRC)
	g++ $(GCCFLAGS) -S $^ -o tmp.s
	c++filt < tmp.s > $@

icpc.out: $(SRC)
	icpc $(ICPCFLAGS) $^ -o $@

icpc.s: $(SRC)
	icpc $(ICPCFLAGS) -S $^ -o tmp.s
	c++filt < tmp.s > $@

run: gcc.out icpc.out
	time ./gcc.out
	time ./icpc.out

clean:
	rm -f gcc.out icpc.out
	rm -f gcc.s icpc.s
