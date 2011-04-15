#include "client.hh"
#include <iostream>


HBClient::HBClient() { }

HBClient::HBClient(string hip, int hport) {
    sock = Socket(AF_INET, hip, hport);
    hostip = hip;
    HBClient();
}

/* Accessor methods */
string HBClient::cname() const {
    return sock.getsrcname();
}

string HBClient::client() const {
    return sock.getsrcip();
}

string HBClient::host() const {
    return sock.getsinip();
}

/* Establish connection to destination */
/* move to its own netops library 
int HBClient::connectsin() {
    return connect(sock.getfd(),
		   sock.getsin(),
		   sizeof(sock.getsin()));
		   }*/

int main() {
    HBClient c("127.0.0.1", 5070);
    cout << "client name: " << c.cname() << endl;
    cout << "client IP: " << c.client() << endl;
    cout << "host IP: " << c.host() << endl;
    return 0;
}
