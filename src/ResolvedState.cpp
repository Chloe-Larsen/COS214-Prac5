#include "../include/ResolvedState.h"
#include "../include/ClosedState.h"

ResolvedState::ResolvedState() : IncidentState()
{
}

void ResolvedState::continueProcess(Incident *incident)
{
    if (incident)
        incident->setState(new ClosedState());
    std::cout << ColourHelper::B_CYAN << ColourHelper::UNDERLINE << "State: Resolve State -> " << incident->getStatusName() << ColourHelper::RESET << ColourHelper::B_CYAN << "\nIncident (" << incident->getIncidentId() << ") has been closed" << ColourHelper::RESET << std::endl;
}

void ResolvedState::dispatch(Incident *incident)
{
    std::cout << ColourHelper::B_CYAN << ColourHelper::UNDERLINE << "State: " << this->getStatusName() << ColourHelper::RESET << ColourHelper::B_CYAN << "\nIncident (" << incident->getIncidentId() << ") cannot be dispatched" << ColourHelper::RESET << std::endl;
}

void ResolvedState::resolve(Incident *incident)
{
    std::cout << ColourHelper::B_CYAN << ColourHelper::UNDERLINE << "State: " << this->getStatusName() << ColourHelper::RESET << ColourHelper::B_CYAN << "\nIncident (" << incident->getIncidentId() << ") cannot be resolved" << ColourHelper::RESET << std::endl;
}

void ResolvedState::close(Incident *incident)
{
    if (incident)
        incident->setState(new ClosedState());
    std::cout << ColourHelper::B_CYAN << ColourHelper::UNDERLINE << "State: Resolve State -> " << incident->getStatusName() << ColourHelper::RESET << ColourHelper::B_CYAN << "\nIncident (" << incident->getIncidentId() << ") has been closed" << ColourHelper::RESET << std::endl;
}

void ResolvedState::cancel(Incident *incident)
{
    std::cout << ColourHelper::B_CYAN << ColourHelper::UNDERLINE << "State: " << this->getStatusName() << ColourHelper::RESET << ColourHelper::B_CYAN << "\nIncident (" << incident->getIncidentId() << ") cannot be canceled" << ColourHelper::RESET << std::endl;
}

std::string ResolvedState::getStatusName() const
{
    return "Resolve State";
}