#include "../include/ReportedState.h"
#include "../include/DispatchedState.h"
#include "../include/ClosedState.h"

ReportedState::ReportedState() : IncidentState()
{
}

void ReportedState::continueProcess(Incident *incident)
{
    if (incident)
        incident->setState(new DispatchedState());
    std::cout << ColourHelper::B_CYAN << ColourHelper::UNDERLINE << "State: Reported State -> " << incident->getStatusName() << ColourHelper::RESET << ColourHelper::B_CYAN << "\nIncident (" << incident->getIncidentId() << ") has been dispatched" << ColourHelper::RESET << std::endl;
}

void ReportedState::dispatch(Incident *incident)
{
    if (incident)
        incident->setState(new DispatchedState());
    std::cout << ColourHelper::B_CYAN << ColourHelper::UNDERLINE << "State: Reported State -> " << incident->getStatusName() << ColourHelper::RESET << ColourHelper::B_CYAN << "\nIncident (" << incident->getIncidentId() << ") has been dispatched" << ColourHelper::RESET << std::endl;
}

void ReportedState::resolve(Incident *incident)
{
    std::cout << ColourHelper::B_CYAN << ColourHelper::UNDERLINE << "State: " << this->getStatusName() << ColourHelper::RESET << ColourHelper::B_CYAN << "\nIncident (" << incident->getIncidentId() << ") cannot be resolved" << ColourHelper::RESET << std::endl;
}

void ReportedState::close(Incident *incident)
{
    std::cout << ColourHelper::B_CYAN << ColourHelper::UNDERLINE << "State: " << this->getStatusName() << ColourHelper::RESET << ColourHelper::B_CYAN << "\nIncident (" << incident->getIncidentId() << ") cannot be closed" << ColourHelper::RESET << std::endl;
}

void ReportedState::cancel(Incident *incident)
{
    if (incident)
        incident->setState(new ClosedState());
    std::cout << ColourHelper::B_CYAN << ColourHelper::UNDERLINE << "State: Reported State -> " << incident->getStatusName() << ColourHelper::RESET << ColourHelper::B_CYAN << "\nIncident (" << incident->getIncidentId() << ") has been canceled" << ColourHelper::RESET << std::endl;
}

std::string ReportedState::getStatusName() const
{
    return "Reported State";
}