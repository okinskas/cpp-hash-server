#include <memory>

#include "HashServer.h"
#include "external/ShaHasher.h"

int main() {

    auto hasher = std::make_unique<ShaHasher>();
    std::make_unique<HashServer>(8080, 20, *hasher)->run();
}
