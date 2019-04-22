#include "Socket.h"

#include <netdb.h>
#include <netinet/in.h>
#include <stdexcept>
#include <strings.h>
#include <cstring>
#include <unistd.h>

Socket::Socket(int port) {

    socketfd = ::socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd < 0) {
        throw std::runtime_error("Failed at: socket creation.");
    }
    struct sockaddr_in addr{};
    bzero((char *) &addr, sizeof(addr));

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    if (bind(socketfd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        throw std::runtime_error("Failed at: port binding " + std::to_string(port));
    }
}

Socket::~Socket() {

    close(socketfd);
}

int Socket::wait() {

    if (listen(socketfd, 20) < 0) {
        throw std::runtime_error("Failed at: listening.");
    }
    sockaddr_in client_addr{};
    socklen_t client_len = sizeof(client_addr);
    int updated_socketfd = accept(socketfd, reinterpret_cast<sockaddr*>(&client_addr), &client_len);
    if (updated_socketfd < 0) {
        throw std::runtime_error("Failed at: accepting input.");
    }
    return updated_socketfd;
}
