#include "../include/IssueAlertCommand.h"

IssueAlertCommand::IssueAlertCommand(CommunicationService *receiver, std::string message, int level) : Command(), receiver(receiver), message(message), level(level)
{
    std::cout << ColourHelper::RED << "Issue Alert Command capabilities have been added to communication service " << receiver->getUnitName()  << " with a message of \"" << message << "\" at level " << level << ColourHelper::RESET << std::endl;
}

IssueAlertCommand::~IssueAlertCommand()
{
}

void IssueAlertCommand::execute()
{
    std::cout << ColourHelper::RED << "Message:" << message << "\n Level: " << level << "\n is being sent to communication service " << receiver->getUnitName() << ColourHelper::RESET << std::endl;
    if(receiver)
        receiver->sendAlert(message, level);
}

void IssueAlertCommand::undo()
{
    std::cout << ColourHelper::RED << "Messages broadcast cannot be unsent"<< ColourHelper::RESET << std::endl;
}