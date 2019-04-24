#include <memory>
#include <iostream>

#include "TerminalUI.h"
#include "HashClient.h"

TerminalUI::TerminalUI(HashClient &hashClient) : mHashClient(hashClient) {}

void TerminalUI::run() {

    printf("Enter a message to hash. Enter \\q to quit.\n\n");

    std::string input;
    std::string hashed;

    while (true) {

        std::getline(std::cin, input);
        if (input == "\\q") break;

        hashed = mHashClient.hashMessage(input);
        std::cout << hashed << std::endl;
    }
}
