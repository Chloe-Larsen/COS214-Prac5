#include "../include/ClosedState.h"

ClosedState::ClosedState() : IncidentState()
{
}

void ClosedState::continueProcess(Incident *incident)
{
    std::cout << ColourHelper::B_CYAN << ColourHelper::UNDERLINE << "State: " << this->getStatusName() << ColourHelper::RESET << ColourHelper::B_CYAN << "\nIncident (" << incident->getIncidentId() << ") cannot be continued" << ColourHelper::RESET << std::endl;
}

void ClosedState::dispatch(Incident *incident)
{
    std::cout << ColourHelper::B_CYAN << ColourHelper::UNDERLINE << "State: " << this->getStatusName() << ColourHelper::RESET << ColourHelper::B_CYAN << "\nIncident (" << incident->getIncidentId() << ") cannot be dispatched" << ColourHelper::RESET << std::endl;
}

void ClosedState::resolve(Incident *incident)
{
    std::cout << ColourHelper::B_CYAN << ColourHelper::UNDERLINE << "State: " << this->getStatusName() << ColourHelper::RESET << ColourHelper::B_CYAN << "\nIncident (" << incident->getIncidentId() << ") cannot be resolved" << ColourHelper::RESET << std::endl;
}

void ClosedState::close(Incident *incident)
{
    std::cout << ColourHelper::B_CYAN << ColourHelper::UNDERLINE << "State: " << this->getStatusName() << ColourHelper::RESET << ColourHelper::B_CYAN << "\nIncident (" << incident->getIncidentId() << ") is already closed" << ColourHelper::RESET << std::endl;
}

void ClosedState::cancel(Incident *incident)
{
    std::cout << ColourHelper::B_CYAN << ColourHelper::UNDERLINE << "State: " << this->getStatusName() << ColourHelper::RESET << ColourHelper::B_CYAN << "\nIncident (" << incident->getIncidentId() << ") cannot be canceled" << ColourHelper::RESET << std::endl;
}

std::string ClosedState::getStatusName() const
{
    return "Closed State";
}
