#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <memory>
#include <thread>
#include <vector>
#include <iostream>
#include <algorithm>

#include "HashServer.h"
#include "Socket.h"
#include "SocketReader.h"
#include "external/ShaHasher.h"

void HashServer::handleSocketConnection(int connection, Hasher &hasher, SocketReader &socketReader) {

    std::string msg = socketReader.readFromSocket(connection);
    std::string hashed = hasher.hashN(msg);
    write(connection, hashed.c_str(), hashed.length());
}

HashServer::HashServer(const int concurrentConnections, Hasher &hasher, Socket &socket, SocketReader &socketReader)
        : mConcurrentConnections(concurrentConnections), mHasher(hasher), mSocket(socket), mSocketReader(socketReader) {}

HashServer::~HashServer() {

    connections.clear();
}

void HashServer::run() {

    initialiseConnections();
    monitorConnections();
}

void HashServer::initialiseConnections() {

    int connection;
    for (int i = 0; i < mConcurrentConnections; i++) {
        connection = mSocket.wait();
        std::thread th(handleSocketConnection, connection, std::ref(mHasher), std::ref(mSocketReader));
        connections.push_back(std::move(th));
    }
}

void HashServer::monitorConnections() {
    while (true) {
        auto iter = std::find_if(
                connections.begin(),
                connections.end(),
                [=](std::thread &t) {
                    return t.joinable();
                }
        );

        if (iter != connections.end()) {
            iter->join();
            connections.erase(iter);
            int connection = mSocket.wait();
            std::thread th(handleSocketConnection, connection, std::ref(mHasher), std::ref(mSocketReader));
            connections.push_back(std::move(th));
        }
    }
}
