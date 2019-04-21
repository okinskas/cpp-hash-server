#include "HashServer.h"

#include <iostream>
#include <memory>

int main() {

    auto server = std::make_unique<HashServer>();
    server->run();
    return 0;
}