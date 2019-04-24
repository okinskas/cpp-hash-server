#include "SHA_Hasher.h"

#include <utility>
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>

#define ROUNDS 10000


SHA_Hasher::SHA_Hasher() {

    rounds = ROUNDS;
}

SHA_Hasher::SHA_Hasher(int rounds) {

    this->rounds = rounds;
}

SHA_Hasher::~SHA_Hasher() = default;

std::string SHA_Hasher::hashN(const std::string &in) {

    std::string out = in;
    for (int i = 0; i < rounds; i++) {
        out = hash(out);
    }
    return out;
}

std::string SHA_Hasher::hash(const std::string &str) {

    // Implementation found here: https://stackoverflow.com/questions/2262386/generate-sha256-with-openssl-and-c
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;
    for (unsigned char i : hash) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int) i;
    }
    return ss.str();
}
