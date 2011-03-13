#include <sys/socket.h>
#include <string>

#include "socket.hh"

using namespace std;

class HBClient {
public:
    HBClient();
    HBClient(string hip, int cport);
    string server() const;
    string cname() const;
    int cport() const;
    string cip() const;
protected:
    Socket sock;
    string hostip;
private:
    int communicate();
};
