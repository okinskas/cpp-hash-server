#include <unistd.h>
#include <stdexcept>
#include <regex>
#include <iostream>
#include <sys/socket.h>
#include "SocketReader.h"


SocketReader::SocketReader() = default;

SocketReader::~SocketReader() = default;

std::string SocketReader::readFromSocket(int connection) {

    char buffer[1028];

    std::size_t incoming = recv(connection, buffer, 1028, 0);

    if (incoming < 0) {
        throw std::runtime_error("Failed at: reading from socket.");
    }

    std::string msg = getMessageFromBuffer(buffer);
    std::cout << msg << std::endl;
    return msg;
}

std::string SocketReader::getMessageFromBuffer(char *buffer){

    std::string full(buffer);
    return full.substr(0, full.find("\\0"));
}
