#ifndef CPP_HASH_SERVER_HASHSERVER_H
#define CPP_HASH_SERVER_HASHSERVER_H


#include <string>
#include <memory>
#include <thread>
#include <vector>

#include "Socket.h"
#include "gateway/Hasher.h"
#include "SocketReader.h"

class HashServer {

public:
    HashServer(int concurrentConnections, Hasher &hasher, Socket &socket, SocketReader &socketReader);
    ~HashServer();
    void run();

private:
    const int mConcurrentConnections;
    std::vector<std::thread> connections;
    Hasher &mHasher;
    Socket &mSocket;
    SocketReader &mSocketReader;
    void initialiseConnections();
    void monitorConnections();
    static void handleSocketConnection(int connection, Hasher &hasher, SocketReader &socketReader);
};


#endif //CPP_HASH_SERVER_HASHSERVER_H
