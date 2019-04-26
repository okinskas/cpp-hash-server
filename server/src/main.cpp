#include <memory>
#include <iostream>

#include "HashServer.h"
#include "external/ShaHasher.h"

int main() {

    const char *concurrent = std::getenv("CONCURRENT");
    std::cout << concurrent << std::endl;
    const char *port = std::getenv("PORT");
    std::cout << port << std::endl;
    int i_int = std::atoi(concurrent);
    int i_port = std::atoi(port);
    std::make_unique<HashServer>(
            i_int,
            i_port,
            *std::make_unique<ShaHasher>()
    )->run();
}
