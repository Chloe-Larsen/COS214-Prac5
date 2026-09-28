#include "OperatorConsole.h"
#include <iostream>

void OperatorConsole::issueCommand(std::unique_ptr<Command> command) {
    command->execute();
    history.push_back(std::move(command));
}

void OperatorConsole::cancelLast() {
    if (history.empty()) {
        std::cout << "[OperatorConsole] no command to cancel\n";
        return;
    }
    history.back()->undo();
    history.pop_back();
}
