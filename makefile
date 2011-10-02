CXX = g++
CXXFLAGS = -Wall -g

all: UDP-info-server.exe 
	
UDP-info-server.exe: binDir UDP-info-server.o Connection.o Server.o
	$(CXX) $(CXXFLAGS) -o main src/UDP-info-server.o src/Connection.o src/Server.o -o bin/UDP-info-server.exe

UDP-info-server.o: 
	$(CXX) $(CXXFLAGS) -c src/UDP-info-server.cpp -o src/UDP-info-server.o

Connection.o:
	$(CXX) $(CXXFLAGS) -c src/Connection.cpp -o src/Connection.o

Server.o:
	$(CXX) $(CXXFLAGS) -c src/Server.cpp -o src/Server.o
	
binDir:
	mkdir bin
	
clean: cleanDir
	rm -f bin/UDP-info-server.exe src/Server.o src/Connection.o src/UDP-info-server.o

cleanDir:
	rm -r bin/