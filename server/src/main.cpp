#include <memory>

#include "HashServer.h"
#include "external/ShaHasher.h"

int main() {

    std::make_unique<HashServer>(
            20,
            *std::make_unique<ShaHasher>(),
            *std::make_unique<Socket>(8080),
            *std::make_unique<SocketReader>()
    )->run();
}
