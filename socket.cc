#include "socket.hh"
#include <iostream>
Socket::Socket(){
    init();
}

Socket::Socket(int p): srcport(p){
    init();
}

Socket::Socket(int sp, int af, string connectto, int destport): srcport(sp){
    init();
    setdest(af, connectto, destport);
}

void Socket::setdest(int af, string connectto, int destport){
    sin.sin_family = af;
    sin.sin_port = htons(destport);
    inet_pton(af,connectto.c_str(),&sin.sin_addr.s_addr);
}

void Socket::init(){
    name = hostname();
    setip();
}

void Socket::setip(){
    ip = ipofhost(name);
}

/* Accessor methods */
string Socket::getsrcname() const{
    return string(name);
}

int Socket::getsrcport() const{
    return srcport;
}

int Socket::getdestport() const{
    return sin.sin_port;
}

string Socket::getsrcip() const{
    return string(ip);
}

string Socket::getdestip() const{
    int family = sin.sin_family;
    char ip[family == AF_INET ? INET_ADDRSTRLEN : INET6_ADDRSTRLEN];
    return string(inet_ntop(family,&sin.sin_addr.s_addr,ip,sizeof(ip)));
}



    


