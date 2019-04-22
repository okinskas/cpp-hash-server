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
#include "external/SHA_Hasher.h"

void HashServer::handleSocketConnection(int connection) {

    auto socketReader = std::make_unique<SocketReader>();
    std::string msg = socketReader->readFromSocket(connection);
    auto hasher = std::make_unique<SHA_Hasher>();
    std::string hashed = hasher->hashN(msg);
    write(connection, hashed.c_str(), hashed.length());
}

HashServer::HashServer(int port, const int concurrentConnections) : mConcurrentConnections(concurrentConnections) {

    mSocket = std::make_unique<Socket>(port);
}

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
        connection = mSocket->wait();
        std::thread th(handleSocketConnection, connection);
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
            int connection = mSocket->wait();
            std::thread th(handleSocketConnection, connection);
            connections.push_back(std::move(th));
        }
    }
}
