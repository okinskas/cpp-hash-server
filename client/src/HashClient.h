#ifndef CPP_HASH_SERVER_HASHCLIENT_H
#define CPP_HASH_SERVER_HASHCLIENT_H


#include <string>

class HashClient {
public:
    HashClient();
    HashClient(const char &serverIp, int serverPort, size_t maxMessageLength);
    ~HashClient()= default;
    std::string hashMessage(const std::string &msg);

private:
    const char *mServerIp;
    int mServerPort;
    size_t mBufferSize;
    int getSocketConnection();
};


#endif //CPP_HASH_SERVER_HASHCLIENT_H
