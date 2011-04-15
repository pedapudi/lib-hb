CC=g++
CXXFLAGS=-g -Wall

all: client server

client: socket.o
	$(CC) $(CXXFLAGS) socket.o client.cc -o client

server: socket.o
	$(CC) $(CXXFLAGS) socket.o server.cc -o server

socket.o: 
	$(CC) $(CXXFLAGS) -c socket.hh socket.cc

clean:
	rm -rf *.o client server *~ *.gch