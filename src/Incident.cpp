#include "../include/Incident.h"
#include "../include/ReportedState.h"

Incident::Incident(std::string incidentId, std::string location, std::string description, int severity) : incidentId(incidentId), location(location), description(description), severity(severity), currentState(nullptr)
{
    std::cout << ColourHelper::B_CYAN << "Incident (" << incidentId << ") with a severity level of " << severity << " at " << location << " - " << description << " has been created" << ColourHelper::RESET << std::endl;
    setState(new ReportedState());
}

Incident::~Incident()
{
    if (currentState != nullptr)
    {
        delete currentState;
    }
    observers.clear();
}

void Incident::setState(IncidentState *state)
{
    if (currentState == state || state == nullptr)
        return;

    std::string oldName = currentState ? currentState->getStatusName() : "<none>";

    if(currentState)
        delete currentState;
    currentState = state;

    std::string newName = currentState->getStatusName();
    notifyObservers(oldName, newName);
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

void Incident::addObserver(IncidentObserver *observer)
{
    if (observer)
        observers.push_back(observer);
}

void Incident::removeObserver(IncidentObserver *observer)
{
    observers.erase(std::remove(observers.begin(), observers.end(), observer),
                    observers.end());
}

void Incident::notifyObservers(const std::string &oldState, const std::string &newState)
{
    for (IncidentObserver *observer : observers)
        if (observer)
            observer->onIncidentStateChanged(this, oldState, newState);
}