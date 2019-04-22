#ifndef CPP_HASH_SERVER_HASHSERVER_H
#define CPP_HASH_SERVER_HASHSERVER_H

#include "Socket.h"

#include <string>
#include <memory>
#include <thread>
#include <vector>

class HashServer {
    const int mConcurrentConnections;
    std::vector<std::thread> connections;
    std::unique_ptr<Socket> mSocket;
public:
    HashServer();
    HashServer(int port, int concurrentConnections);
    ~HashServer();
    void run();

private:
    void initialiseConnections();
    void monitorConnections();
    static void handleSocketConnection(int connection);
};


#endif //CPP_HASH_SERVER_HASHSERVER_H
