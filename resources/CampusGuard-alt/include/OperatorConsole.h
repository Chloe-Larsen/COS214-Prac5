#pragma once
#include "Command.h"
#include <memory>
#include <vector>

// Invoker: the operator's console. It doesn't know what a command does,
// only that it can be executed (and, where supported, undone).
class OperatorConsole {
public:
    void issueCommand(std::unique_ptr<Command> command);
    void cancelLast();

private:
    std::vector<std::unique_ptr<Command>> history; // OperatorConsole owns issued commands
};
