#include "../include/LockAreaCommand.h"

LockAreaCommand::LockAreaCommand(AreaComponent *receiver) : Command(), receiver(receiver)
{
    std::cout << ColourHelper::RED << "Lock Area Command capabilities have been added to" << receiver->getName() << ColourHelper::RESET << std::endl;
}

LockAreaCommand::~LockAreaCommand()
{
}

void LockAreaCommand::execute()
{
    std::cout << ColourHelper::RED << receiver->getName() << " is getting locked:" << ColourHelper::RESET << std::endl;
    if (receiver)
        receiver->lock();
}

void LockAreaCommand::undo()
{
    std::cout << ColourHelper::RED << receiver->getName() << " is getting unlocked:" << ColourHelper::RESET << std::endl;
    if (receiver)
        receiver->unlock();
}