CXX=g++
LD=g++

cxx=$(wildcard src/*.cpp)

.DEFAULT_GOAL := all

%.cpp.o: %.cpp
	$(CXX) -DDEBUG -c -gdwarf-2  -ggdb -I./include -o $@ $?

all: $(addsuffix .o, $(cxx))
	$(LD) $(wildcard src/*.cpp.o) -o main.exe