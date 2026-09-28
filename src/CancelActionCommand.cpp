#include "../include/CancelActionCommand.h"

CancelActionCommand::CancelActionCommand(Incident *targetIncident) : Command(), targetIncident(targetIncident)
{
    std::cout << ColourHelper::RED << "Cancel Action Command capabilities have been added to Incident(" << targetIncident->getIncidentId() << ")" << ColourHelper::RESET << std::endl;
}

CancelActionCommand::~CancelActionCommand()
{
}

void CancelActionCommand::execute()
{    
    std::cout << ColourHelper::RED << "Incident (" << targetIncident->getIncidentId() << ") is being canceled" << ColourHelper::RESET << std::endl;
    if (targetIncident)
        targetIncident->cancel();
}

void CancelActionCommand::undo()
{
    std::cout << ColourHelper::RED << "Incident (" << targetIncident->getIncidentId() << ") cannot be un-canceled" << ColourHelper::RESET << std::endl;
}