#include "../include/IncidentCoordinator.h"

IncidentCoordinator::IncidentCoordinator() : ResponseMediator()
{
}

IncidentCoordinator::~IncidentCoordinator()
{
}

void IncidentCoordinator::registerColleague(ResponseUnit *unit)
{
    if (!unit)
        return;

    std::cout << ColourHelper::B_YELLOW << "Adding " << unit->getUnitName() << " unit to Incident Coordinator" << ColourHelper::RESET << std::endl;
    colleagues.push_back(unit);
    unit->setMediator(this);
}

void IncidentCoordinator::notify(ResponseUnit *sender, std::string event)
{
    const std::string senderName = sender ? sender->getUnitName() : "<unknown>";
    std::cout << ColourHelper::B_YELLOW << "Coordinator event " << event << " From " << senderName << ColourHelper::RESET << std::endl;

    if (event == "security-dispatched")
    {
        for (ResponseUnit *unit : colleagues)
        {
            if (unit != sender)
                unit->send("incident-active");
        }
    }
    else if (event == "area-unsafe")
    {
        for (ResponseUnit *unit : colleagues)
        {
            if (unit->getUnitName().find("Facilities") != std::string::npos)
            {
                unit->send("secure-area");
            }
            else if (unit->getUnitName().find("Communication") != std::string::npos)
            {
                unit->send("broadcast-alert");
            }
        }
    }
    else if (event == "medical-dispatched")
    {
        for (ResponseUnit *unit : colleagues)
        {
            if (unit != sender)
                unit->send("medical-on-scene");
        }
    }
    else if (event == "facilities-dispatched")
    {
        for (ResponseUnit *unit : colleagues)
        {
            if (unit != sender)
                unit->send("facilities-on-scene");
        }
    }
    else if (event == "area-secured")
    {
        for (ResponseUnit *unit : colleagues)
        {
            if (unit != sender)
                unit->send("area-secured");
        }
    }
    else
    {
        std::cout << ColourHelper::B_YELLOW << "Coordinator no reaction configured fors " << event << ColourHelper::RESET << std::endl;
    }
}

void IncidentCoordinator::dispatchAll(Incident *incident)
{
    if (!incident)
        return;
    std::cout << ColourHelper::B_YELLOW << "Coordinator dispatching all registered units for incident (" << incident->getIncidentId() << ")" << ColourHelper::RESET << std::endl;
    for (ResponseUnit *unit : colleagues)
    {
        unit->dispatch(incident);
    }
}