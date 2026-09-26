#include "../include/Incident.h"
#include "../include/ReportedState.h"

Incident::Incident(std::string incidentId, std::string location, std::string description, int severity) : incidentId(incidentId), location(location), description(description), severity(severity)
{
    std::cout << ColourHelper::B_CYAN << "Incident (" << incidentId << ") with a severity level of " << severity << " at " << location << " - " << description  << " has been created"<< ColourHelper::RESET << std::endl;
    currentState = new ReportedState();
}

Incident::~Incident()
{
    if (currentState != nullptr)
    {
        delete currentState;
    }
}

void Incident::setState(IncidentState *state)
{
    if (currentState != state)
    {
        if (currentState != nullptr)
            delete currentState;
        currentState = state;
    }
}

void Incident::continueProcess()
{
    currentState->continueProcess(this);
}

void Incident::dispatch()
{
    currentState->dispatch(this);
}

void Incident::resolve()
{
    currentState->resolve(this);
}

void Incident::close()
{
    currentState->close(this);
}

void Incident::cancel()
{
    currentState->cancel(this);
}

std::string Incident::getStatusName() const
{
    return currentState->getStatusName();
}

std::string Incident::getIncidentId() const
{
    return incidentId;
}