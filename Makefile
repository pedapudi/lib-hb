CC=g++
CFLAGS=-c -Wall

all: client server

client: socket.o
	$(CC) socket.o client.cc -o client

server: socket.o
	$(CC) socket.o server.cc -o server

socket.o: 
	$(CC) $(CFLAGS) socket.hh socket.cc

clean:
	rm -rf *.o client server *~ *.gch