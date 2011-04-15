#include "socket.hh"

using namespace std;

class NetOp {
public:
    /* Establish connection to destination */
    int sockconnect(Socket sock);

    /* Binds socket to fd */
    int sockbind(Socket sock, int fd);

    /* Begin listening on given socket */
    int socklisten(int fd);

    /* Accept connetion on given socket */
    Socket sockaccept(Socket sock, int fd);

    
