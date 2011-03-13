#include <sys/socket.h>
#include <string>

#include "socket.hh"

using namespace std;

class HBClient {
public:
    HBClient();
    HBClient(string hip, int cport);
private:
    int communicate();
    static string clientname;
    static string clientip;
    static int clientport;
    static string hostip;
};
