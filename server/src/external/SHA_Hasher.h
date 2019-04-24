#ifndef CPP_HASH_SERVER_SHA_HASHER_H
#define CPP_HASH_SERVER_SHA_HASHER_H

#include <string>
#include "../server/gateway/Hasher.h"

class SHA_Hasher {
    int rounds;
public:
    SHA_Hasher();
    explicit SHA_Hasher(int rounds);
    ~SHA_Hasher();
    std::string hash(const std::string &in);
    std::string hashN(const std::string &in);
};


#endif //CPP_HASH_SERVER_SHA_HASHER_H
