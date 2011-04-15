#include <arpa/inet.h>
#include <ifaddrs.h>
#include <string>

#include "socket.hh"

using namespace std;

class HBServer {
public:
    HBServer(int hport);

    int bindsin();
    int listensin();
    int acceptconn();
    
protected:
    Socket sock;
    string hostip;
};
