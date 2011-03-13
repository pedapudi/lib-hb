#include "client.hh"
#include <iostream>


HBClient::HBClient(){
}

HBClient::HBClient(int cport){
    sock = Socket(cport);
    HBClient();
}

HBClient::HBClient(int cport, string hip, int hport){
    sock = Socket(cport, AF_INET, hip, hport);
    hostip = hip;
    HBClient();
}

int HBClient::communicate(){
}

/* Accessor methods */
string HBClient::cname() const{
    return sock.getsrcname();
}

int HBClient::cport() const{
    return sock.getsrcport();
}

string HBClient::client() const{
    return sock.getsrcip();
}

string HBClient::host() const{
    return sock.getdestip();
}

int main(){
    HBClient c(7050, "127.0.0.1", 5070);
    cout << "client name: " << c.cname() << endl;
    cout << "client-side port: " << c.cport() << endl;
    cout << "client IP: " << c.client() << endl;
    cout << "host IP: " << c.host() << endl;
    return 0;
}
