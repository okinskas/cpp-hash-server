#ifndef CPP_HASH_SERVER_SOCKET_H
#define CPP_HASH_SERVER_SOCKET_H


#include <string>

class Socket {

public:
    explicit Socket(int port);
    ~Socket();
    int wait();

private:
    int socketfd;
};


#endif //CPP_HASH_SERVER_SOCKET_H
