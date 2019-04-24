#ifndef CLIENT_TERMINALUI_H
#define CLIENT_TERMINALUI_H


#include <string>

#include "HashClient.h"

class TerminalUI {
public:
    explicit TerminalUI(HashClient &hashClient);
    ~TerminalUI()= default;
    void run();

private:
    HashClient &mHashClient;
};


#endif //CLIENT_TERMINALUI_H
