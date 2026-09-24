#include "../include/DispatchedState.h"
#include "../include/InProgressState.h"
#include "../include/ClosedState.h"

DispatchedState::DispatchedState() : IncidentState()
{
}

void DispatchedState::continueProcess(Incident *incident)
{
    if (incident)
        incident->setState(new InProgressState());
    std::cout << ColourHelper::B_CYAN << ColourHelper::UNDERLINE << "State: Dispatched State -> " << incident->getStatusName() << ColourHelper::RESET << ColourHelper::B_CYAN << "\nIncident (" << incident->getIncidentId() << ") is now in progress" << ColourHelper::RESET << std::endl;
}

void DispatchedState::dispatch(Incident *incident)
{
    std::cout << ColourHelper::B_CYAN << ColourHelper::UNDERLINE << "State: " << this->getStatusName() << ColourHelper::RESET << ColourHelper::B_CYAN << "\nIncident (" << incident->getIncidentId() << ") has already been dispatched" << ColourHelper::RESET << std::endl;
}

void DispatchedState::resolve(Incident *incident)
{
    std::cout << ColourHelper::B_CYAN << ColourHelper::UNDERLINE << "State: " << this->getStatusName() << ColourHelper::RESET << ColourHelper::B_CYAN << "\nIncident (" << incident->getIncidentId() << ") cannot be resolved" << ColourHelper::RESET << std::endl;
}

void DispatchedState::close(Incident *incident)
{
    std::cout << ColourHelper::B_CYAN << ColourHelper::UNDERLINE << "State: " << this->getStatusName() << ColourHelper::RESET << ColourHelper::B_CYAN << "\nIncident (" << incident->getIncidentId() << ") cannot be closed" << ColourHelper::RESET << std::endl;
}

void DispatchedState::cancel(Incident *incident)
{
    if (incident)
        incident->setState(new ClosedState());
    std::cout << ColourHelper::B_CYAN << ColourHelper::UNDERLINE << "State: Dispatched State -> " << incident->getStatusName() << ColourHelper::RESET << ColourHelper::B_CYAN << "\nIncident (" << incident->getIncidentId() << ") has been canceled" << ColourHelper::RESET << std::endl;
}

std::string DispatchedState::getStatusName() const
{
    return "Dispatched State";
}