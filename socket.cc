#include "socket.hh"
#include <iostream>
Socket::Socket() {
    init();
}

Socket::Socket(int af, string connectto, int destport) {
    init();
    setsin(af, connectto, destport);
}

/* Setter methods */
void Socket::init() {
    name = hostname();
    setip();
    setfd();
}

void Socket::setsin(int af, string connectto, int destport) {
    sin.sin_family = af;
    sin.sin_port = htons(destport);
    inet_pton(af,connectto.c_str(),&sin.sin_addr.s_addr);
}

void Socket::setip() {
    ip = ipofhost(name);
}

int Socket::setfd(int fdesc) {
    fd = fdesc;
    return fd;
}

int Socket::setfd() {
    return setfd(socket(sin.sin_family, SOCK_STREAM, 0));
}
		     
/* Accessor methods */
string Socket::getsrcname() const {
    return string(name);
}

int Socket::getsinport() const {
    return sin.sin_port;
}

string Socket::getsrcip() const {
    return string(ip);
}

string Socket::getsinip() const {
    int family = sin.sin_family;
    char ip[family == AF_INET ? INET_ADDRSTRLEN : INET6_ADDRSTRLEN];
    return string(inet_ntop(family,
			    &sin.sin_addr.s_addr,
			    ip, sizeof(ip)));
}

int Socket::getfd() const {
    return fd;
}

struct sockaddr* Socket::getsin() const {
    return (struct sockaddr *) &sin;
}

pair<Socket, Socket> SockSet::make_pair(Socket sock, bool r, bool w) {
    pair<Socket, Socket> sockpair;
    
    if(r)
	sockpair.first = sock;
    if(w)
	sockpair.second = sock;
	
    return sockpair;
}

void SockSet::sockset_zero() {
    sset.clear();
    FD_ZERO(&rfdset);
    FD_ZERO(&wfdset);
}

void SockSet::sockset_addreadable(Socket sock) {
    FD_SET(sock.getfd(), &rfdset);
    sset[sock.getfd()] = make_pair(sock, true, false);
    maxfd = (maxfd < sock.getfd() ?
	     sock.getfd() :
	     maxfd);
}

void SockSet::sockset_addwriteable(Socket sock) {
    FD_SET(sock.getfd(), &wfdset);
    sset[sock.getfd()] = make_pair(sock, false, true);
    maxfd = (maxfd < sock.getfd() ?
	     sock.getfd() :
	     maxfd);
}

void SockSet::sockset_add(Socket sock) {
    sockset_addreadable(sock);
    sockset_addwriteable(sock);
}

bool SockSet::sockset_isreadable(Socket sock) {
    pair<Socket, Socket> sockpair;
    if(sset.find(sock.getfd() == sset.end())) {
	sockpair = NULL;
    } else {
	sockpair = sset[sock.getfd()];
    }
    
    if(sockpair != NULL) {
	if(sockpair.first != NULL) {
	    return FD_ISSET(sockpair.first.getfd(), &rfdset);
	}
    }
    return false;
}

bool SockSet::sockset_iswriteable(Socket sock) {
    pair<Socket, Socket> sockpair;
    if(sset.find(sock.getfd() == sset.end())) {
	sockpair = NULL;
    } else {
	sockpair = sset[sock.getfd()];
    }
    
    if(sockpair != NULL) {
	if(sockpair.second != NULL) {
	    return FD_ISSET(sockpair.second.getfd(), &wfdset);
	}
    }
    return false;
}

bool SockSet::sockset_isset(Socket sock) {
    return (sockset_iswriteable(sock) ||
	    sockset_isreadable(sock));
}

pair<Socket, Socket> SockSet::sockset_select() {
    return sset[select(maxfd+1, &rfdset, &wfdset, NULL, NULL)];
}

fd_set SockSet::getrfdset() const {
    return rfdset;
}

fd_set SockSet::getwfdset() const {
    return wfdset;
}
