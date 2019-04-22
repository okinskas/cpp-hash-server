#include "HashServer.h"

#include <memory>

int main() {

    auto server = std::make_unique<HashServer>(8080, 3);
    server->run();
}
