#include "server.hh"
#include <iostream>

HBServer::HBServer(int hport) {
    sock.setsin(AF_INET, sock.getsrcip(), hport);
}

int HBServer::bindsin() {
    return bind(sock.getfd(),
		sock.getsin(),
		sizeof(sock.getsin()));
}

int HBServer::listensin() {
    return listen(sock.getfd(), 512);
}

int HBServer::acceptconn() {
    struct sockaddr_in client_sin;
    int addr_len = sizeof(client_sin);
    int listening_fd = sock.getfd();
    while(1) {
	int max_fd = listening_fd;
	
	fd_set readable;
	FD_ZERO(&readable);
	FD_SET(listening_fd, &readable);
	
	if(select(max_fd+1, &readable, NULL, NULL, NULL) < 0) {
	    continue;
	}
	
	if(FD_ISSET(listening_fd, &readable)) {
	    int client_sock = accept(listening_fd,
				     (struct sockaddr *) &client_sin,
				     (socklen_t *) &addr_len);
	    if (client_sock < 0){
		cout << "Bad FD after accept" << endl;
	    }
	    
	    max_fd = ((max_fd < client_sock) ? 
		      client_sock :
		      max_fd);
	}
    }
}

int main() {
    HBServer s(2048);
    cout << "successfully created HBServer object" << endl;
}
