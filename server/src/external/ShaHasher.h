#ifndef CPP_HASH_SERVER_SHA_HASHER_H
#define CPP_HASH_SERVER_SHA_HASHER_H

#include <string>
#include "../gateway/Hasher.h"

class ShaHasher : public Hasher {

public:
    ShaHasher();
    explicit ShaHasher(int rounds);
    std::string hash(const std::string &in) override;
    std::string hashN(const std::string &in) override;

private:
    int mRounds;
};


#endif //CPP_HASH_SERVER_SHA_HASHER_H
