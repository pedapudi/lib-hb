#include <arpa/inet.h>
#include <netdb.h>
#include <string>
#define MTU 1500
using namespace std;

class Socket {
public:
    Socket();
    Socket(int srcport);
    Socket(int srcport, int af, string connectto, int destport);

    static string hostname(){
        char hname[255];
        gethostname(hname,255);
        return string(hname);
    }

    static string ipofhost(string name){
        struct hostent *host = gethostbyname(name.c_str());
        char ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, ((struct in_addr *)
                            (host->h_addr_list[0])),
                  ip, INET_ADDRSTRLEN);
        return string(ip);
    }

    string getsrcname() const;
    string getsrcip() const;
    string getdestip() const;
    int getsrcport() const;
    int getdestport() const;
    

private:
    void setdest(int af, string connectto, int destport);
    void setip();
    void init();
    struct sockaddr_in sin;
    string name;
    string ip;
    int srcport;
};
