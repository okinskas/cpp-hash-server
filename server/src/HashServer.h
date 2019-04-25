#ifndef CPP_HASH_SERVER_HASHSERVER_H
#define CPP_HASH_SERVER_HASHSERVER_H


#include <string>
#include <memory>
#include <thread>
#include <vector>

#include "Socket.h"
#include "gateway/Hasher.h"

class HashServer {

public:
    HashServer(int port, int concurrentConnections, Hasher &hasher);
    ~HashServer();
    void run();

private:
    const int mConcurrentConnections;
    std::vector<std::thread> connections;
    std::unique_ptr<Socket> mSocket;
    Hasher &mHasher;
    void initialiseConnections();
    void monitorConnections();
    static void handleSocketConnection(int connection, Hasher &hasher);
};


#endif //CPP_HASH_SERVER_HASHSERVER_H
