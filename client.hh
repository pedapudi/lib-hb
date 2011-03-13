#include <arpa/inet.h>
#include <string>

#include "socket.hh"

using namespace std;

class HBClient {
public:
    HBClient();
    HBClient(int cport);
    HBClient(int cport, string hip, int hport);

    string cname() const;
    int cport() const;
    string client() const;
    string host() const;

protected:
    Socket sock;
    string hostip;

private:
    int communicate();
};
