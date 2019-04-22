#include <utility>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdexcept>

#include "HashClient.h"

HashClient::HashClient() {

    mServerIp = "0.0.0.0";
    mServerPort = 8080;
    mBufferSize = 256;
}

HashClient::HashClient(const char &serverIp, int serverPort, size_t maxMessageLength) {

    mServerIp = &serverIp;
    mServerPort = serverPort;
    mBufferSize = maxMessageLength;
}

std::string HashClient::hashMessage(const std::string &msg) {

    int sock = getSocketConnection();
    char buffer[mBufferSize];
    memset(buffer, 0, mBufferSize);

    send(sock, msg.c_str(), msg.size(), 0);
    recv(sock , buffer, mBufferSize, 0);

    return buffer;
}

int HashClient::getSocketConnection() {
    int sock = 0;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        throw std::runtime_error("Failed at: socket creation.");
    }

    struct sockaddr_in serv_addr{};
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(mServerPort);

    if(inet_pton(AF_INET, mServerIp, &serv_addr.sin_addr) <= 0) {
        throw std::runtime_error("Failed at: address vetting.");
    }

    if (connect(sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        throw std::runtime_error("Failed at: connection to server.");
    }

    return sock;
}
