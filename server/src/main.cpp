#include <memory>

#include "HashServer.h"

int main() {

    std::make_unique<HashServer>(8080, 20)->run();
}
