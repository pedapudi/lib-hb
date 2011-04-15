#include <arpa/inet.h>
#include <string>

#include "socket.hh"

using namespace std;

class HBClient {
public:
    HBClient();
    HBClient(string hip, int hport);

    string cname() const;
    string client() const;
    string host() const;

protected:
    Socket sock;
    string hostip;

private:
    
};
