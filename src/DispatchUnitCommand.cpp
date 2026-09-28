#include "../include/DispatchUnitCommand.h"

DispatchUnitCommand::DispatchUnitCommand(ResponseUnit *receiver, Incident *targetIncident) : Command(), receiver(receiver), targetIncident(targetIncident)
{
    std::cout << ColourHelper::RED << "Dispatch Unit Command capabilities have been added to Incident(" << targetIncident->getIncidentId() << ") for Response unit " << receiver->getUnitName() << ColourHelper::RESET << std::endl;
}

DispatchUnitCommand::~DispatchUnitCommand()
{
}

void DispatchUnitCommand::execute()
{
    std::cout << ColourHelper::RED << "Units to incident (" << targetIncident->getIncidentId() << ") through response unit " << receiver->getUnitName() << " have been dispatched" << ColourHelper::RESET << std::endl;
    if (receiver)
        receiver->dispatch(targetIncident);
}

void DispatchUnitCommand::undo()
{
    std::cout << ColourHelper::RED << "Units to incident (" << targetIncident->getIncidentId() << ") through response unit " << receiver->getUnitName() << " have been cancelled" << ColourHelper::RESET << std::endl;
    if (targetIncident)
        targetIncident->cancel();
}