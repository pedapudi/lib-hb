#include "netop.hh"

using namespace std;

int NetOp::connect(Socket sock) {
    return connect(sock.getfd(),
		   sock.getsin(),
		   sizeof(sock.getsin()));
}

int NetOp::bind(Socket sock, int fd) {
    return bind(fd, sock.getsin(),
		sizeof(sock.getsin()));
}

int NetOp::socklisten(int fd) {
    return listen(fd, 512);
}

Socket NetOp::sockaccept(Socket sock, int fd) {
    Socket client;
    client.setfd(accept(fd, client.getsin(),
			(socklen_t *) &sizeof(client.getsin())));
}



