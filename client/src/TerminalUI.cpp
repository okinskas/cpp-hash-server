#include <memory>
#include <iostream>

#include "TerminalUI.h"
#include "HashClient.h"

TerminalUI::TerminalUI() {

    mClient = std::make_unique<HashClient>();
}

void TerminalUI::run() {

    printf("Enter a message to hash. Enter \\q to quit.\n");

    std::string input;
    std::string hashed;

    while (true) {

        std::getline(std::cin, input);
        if (input == "\\q") break;

        hashed = mClient->hashMessage(input);
        std::cout << hashed << std::endl;
    }
}
