#include <bits/unique_ptr.h>

#include "TerminalUI.h"

int main() {

    std::make_unique<TerminalUI>()->run();
    return 0;
}
