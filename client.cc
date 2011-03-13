#include "client.hh"
#include <iostream>


HBClient::HBClient(){
}

HBClient::HBClient(string hip, int cport){
    sock = Socket(cport);
    hostip = hip;
    HBClient();
}

int HBClient::communicate(){
}

/* Accessor methods */
string HBClient::server() const{
    return string(hostip);
}

string HBClient::cname() const{
    return string(sock.name);
}

int HBClient::cport() const{
    return sock.port;
}

string HBClient::cip() const{
    return string(sock.ip);
}

int main(){
    HBClient c("127.0.0.1", 5070);
    cout << "client name: " << c.cname() << endl;
    cout << "client-side port: " << c.cport() << endl;
    cout << "client IP: " << c.cip() << endl;
    return 0;
}
