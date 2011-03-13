#include <arpa/inet.h>
#include <netdb.h>
#include <string>

using namespace std;

class Socket {
public:
    Socket();
    Socket(int port);
    string name;
    string ip;
    int port;

    static string hostname(){
        char name[255];
        gethostname(name,255);
        return string(name);
    }

    static string ipofhost(string name){
        struct hostent *host = gethostbyname(name.c_str());
        char ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, ((struct in_addr *)
                            (host->h_addr_list[0])),
                  ip, INET_ADDRSTRLEN);
        return string(ip);
    }    
};
