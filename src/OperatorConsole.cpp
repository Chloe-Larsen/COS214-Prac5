#include "../include/OperatorConsole.h"

OperatorConsole::OperatorConsole()
{
}

OperatorConsole::~OperatorConsole()
{
    for (Command *command : history)
    {
        delete command;
    }
    history.clear();
}

void OperatorConsole::executeCommand(Command *command)
{
    if (!command)
    {
        std::cout << ColourHelper::RED << "No command supplied — nothing executed." << ColourHelper::RESET << std::endl;
        return;
    }

    command->execute();
    history.push_back(command);
}

void OperatorConsole::undoLast()
{
    if (history.empty())
    {
        std::cout << ColourHelper::RED << "Nothing to do — history is empty." << ColourHelper::RESET << std::endl;
        return;
    }

    Command *last = history.back();
    history.pop_back();
    last->undo();
    delete last;
}