CXX = g++

CXXFLAGS= -std=c++11 -Wall -g

prog1A: hashTable.o main.o 
	${CXX} $^ -o $@

clean:
	/bin/rm -f *.o prog1A