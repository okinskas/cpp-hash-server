#ifndef CPP_HASH_SERVER_SOCKETREADER_H
#define CPP_HASH_SERVER_SOCKETREADER_H


#include <string>

class SocketReader {

public:
    SocketReader();
    ~SocketReader();

    std::string readFromSocket(int connection);
private:
    static std::string getMessageFromBuffer(char* buffer);
};


#endif //CPP_HASH_SERVER_SOCKETREADER_H
