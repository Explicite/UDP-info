CXX = g++
CXXFLAGS = -Wall -g

all: main.exe
	
main.exe: binDir main.o Connection.o Server.o
	$(CXX) $(CXXFLAGS) -o main src/main.o src/Connection.o src/Server.o -o bin/main.exe

main.o: 
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o src/main.o

Connection.o:
	$(CXX) $(CXXFLAGS) -c src/Connection.cpp -o src/Connection.o

Server.o:
	$(CXX) $(CXXFLAGS) -c src/Server.cpp -o src/Server.o
	
binDir:
	mkdir bin
	
clean: cleanDir
	rm -f bin/main.exe src/Server.o src/Connection.o src/main.o

cleanDir:
	rm -r bin/