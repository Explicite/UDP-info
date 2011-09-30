CXX = g++
CXXFLAGS = -Wall -g

all: main.exe
	
main.exe: binDir main.o functions.o 
	$(CXX) $(CXXFLAGS) -o main src/main.o src/functions.o -o bin/main.exe

main.o: 
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o src/main.o

functions.o:
	$(CXX) $(CXXFLAGS) -c src/functions.cpp -o src/functions.o

binDir:
	mkdir bin
	
clean: cleanDir
	rm -f bin/main.exe src/functions.o src/main.o

cleanDir:
	rm -r bin/