#ifndef CPP_HASH_SERVER_SOCKET_H
#define CPP_HASH_SERVER_SOCKET_H


#include <string>

class Socket {
    int socketfd;
public:
    explicit Socket(int port);
    ~Socket();
    int wait();
};


#endif //CPP_HASH_SERVER_SOCKET_H
