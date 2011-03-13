#include "client.hh"
#include <iostream>


string HBClient::clientname;
int HBClient::clientport;
string HBClient::hostip;
string HBClient::clientip;

HBClient::HBClient(){
    clientname = Socket::hostname();
    clientip = Socket::ipofhost(clientname);
}

HBClient::HBClient(string hip, int cport){
    clientport = cport;
    hostip = hip;
    HBClient();
    cout << hostip << endl;
    cout << clientname << endl;
    cout << clientport << endl;
    cout << clientip << endl;
}

int HBClient::communicate(){
}

int main(){
    HBClient c("127.0.0.1", 5070);
    return 0;
}
