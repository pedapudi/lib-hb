#include "socket.hh"
#include <iostream>
Socket::Socket(){
}

Socket::Socket(int p): name(hostname()), port(p){
    ip = ipofhost(name);
}
