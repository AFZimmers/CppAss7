#Makefile for Assignment 7
#Alexander Zimmermann ZMMALE001

CC=g++
CCFLAGS=-std=c++11

SRC = $(wildcard src/*.cpp *.h)
OBJ = $(SRC:.cpp=.o)

PROG = perceptron

$(PROG) : $(OBJ)
	$(CC) $(CCFLAGS) $(SRC) -o perceptron
	
.cpp.o:
	$(CC) $(CCFLAGS) -c $<

depend:
	$(CC) -M $(SRC) > incl.defs

clean:
	rm -f *.o
	rm -f perceptron
