#ifndef CLIENT_TERMINALUI_H
#define CLIENT_TERMINALUI_H


#include <string>

#include "HashClient.h"

class TerminalUI {
public:
    TerminalUI();
    ~TerminalUI()= default;
    void run();

private:
    std::unique_ptr<HashClient> mClient;
};


#endif //CLIENT_TERMINALUI_H
