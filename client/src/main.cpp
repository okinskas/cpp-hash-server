#include <memory>
#include "TerminalUI.h"

int main() {

    auto hashClient = std::make_unique<HashClient>();
    std::make_unique<TerminalUI>(*hashClient)->run();
    return 0;
}
