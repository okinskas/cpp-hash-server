#include <memory>

#include "HashServer.h"
#include "external/ShaHasher.h"

int main() {

    std::make_unique<HashServer>(
            20,
            8080,
            *std::make_unique<ShaHasher>()
    )->run();
}
