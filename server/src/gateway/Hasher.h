#ifndef CPP_HASH_SERVER_HASHER_H
#define CPP_HASH_SERVER_HASHER_H

#include <string>

class Hasher {

public:
    virtual ~Hasher()= default;
    virtual std::string hash(const std::string &in) = 0;
    virtual std::string hashN(const std::string &in) = 0;

private:
    int mRounds;
};

#endif //CPP_HASH_SERVER_HASHER_H
