#include "../include/InProgressState.h"
#include "../include/ResolvedState.h"
#include "../include/ClosedState.h"

InProgressState::InProgressState() : IncidentState()
{
}

void InProgressState::continueProcess(Incident *incident)
{
    if (incident)
        incident->setState(new ResolvedState());
    std::cout << ColourHelper::B_CYAN << ColourHelper::UNDERLINE << "State: In Progress State -> " << incident->getStatusName() << ColourHelper::RESET << ColourHelper::B_CYAN << "\nIncident (" << incident->getIncidentId() << ") is being resolved" << ColourHelper::RESET << std::endl;
}

void InProgressState::dispatch(Incident *incident)
{
    std::cout << ColourHelper::B_CYAN << ColourHelper::UNDERLINE << "State: " << this->getStatusName() << ColourHelper::RESET << ColourHelper::B_CYAN << "\nIncident (" << incident->getIncidentId() << ") cannot be dispatched" << ColourHelper::RESET << std::endl;
}

void InProgressState::resolve(Incident *incident)
{
    if (incident)
        incident->setState(new ResolvedState());
    std::cout << ColourHelper::B_CYAN << ColourHelper::UNDERLINE << "State: In Progress State -> " << incident->getStatusName() << ColourHelper::RESET << ColourHelper::B_CYAN << "\nIncident (" << incident->getIncidentId() << ") is being resolved" << ColourHelper::RESET << std::endl;
}

void InProgressState::close(Incident *incident)
{
    std::cout << ColourHelper::B_CYAN << ColourHelper::UNDERLINE << "State: " << this->getStatusName() << ColourHelper::RESET << ColourHelper::B_CYAN << "\nIncident (" << incident->getIncidentId() << ") cannot be closed" << ColourHelper::RESET << std::endl;
}

void InProgressState::cancel(Incident *incident)
{
    if (incident)
        incident->setState(new ClosedState());
    std::cout << ColourHelper::B_CYAN << ColourHelper::UNDERLINE << "State: In Progress State -> " << incident->getStatusName() << ColourHelper::RESET << ColourHelper::B_CYAN << "\nIncident (" << incident->getIncidentId() << ") has been canceled" << ColourHelper::RESET << std::endl;
}

std::string InProgressState::getStatusName() const
{
    return "In Progress State";
}