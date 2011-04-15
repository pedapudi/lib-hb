#include <arpa/inet.h>
#include <netdb.h>
#include <string>
#include <map>
#include <utility>

#define MTU 1500

using namespace std;

class Socket {
public:
    Socket();
    Socket(int af, string connectto, int destport);

    static string hostname() {
        char hname[255];
        gethostname(hname,255);
        return string(hname);
    }

    static string ipofhost(string name) {
        struct hostent *host = gethostbyname(name.c_str());
        char ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, ((struct in_addr *)
                            (host->h_addr_list[0])),
                  ip, INET_ADDRSTRLEN);
        return string(ip);
    }

    string getsrcname() const;
    string getsrcip() const;
    string getsinip() const;
    int getsinport() const;
    int getfd() const;
    struct sockaddr* getsin() const;
    
    int setfd();
    int setfd(int fdesc);
    void setsin(int af, string connectto, int destport);
    
protected:
    void setip();
    void init();
    struct sockaddr_in sin;
    string name;
    string ip;
    int fd;
};

class SockSet {
public:
    void sockset_zero();
    void sockset_addreadable(Socket sock);
    void sockset_addwriteable(Socket sock);
    void sockset_add(Socket sock);
    bool sockset_isreadable(Socket sock);
    bool sockset_iswriteable(Socket sock);
    bool sockset_isset(Socket sock);
    pair<Socket, Socket> sockset_select();
    fd_set sockset_as_fd_set();

    fd_set getrfdset() const;
    fd_set getwdfset() const;

protected:
    pair<Socket, Socket> make_pair(Socket sock, bool r, bool w);
    
private:
    map<int, pair<Socket, Socket> > sset;
    fd_set rfdset;
    fd_set wfdset;
    int maxfd;
};
