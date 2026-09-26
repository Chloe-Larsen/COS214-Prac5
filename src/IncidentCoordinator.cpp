#include "../include/IncidentCoordinator.h"

IncidentCoordinator::IncidentCoordinator() : ResponseMediator()
{
    std::cout << ColourHelper::B_YELLOW << "New incident coordinator has been created" << ColourHelper::RESET << std::endl;
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

static ResponseUnit *findColleague(const std::vector<ResponseUnit *> &colleagues,
                                   const std::string &needle)
{
    for (ResponseUnit *u : colleagues)
        if (u && u->getUnitName().find(needle) != std::string::npos)
            return u;
    return nullptr;
}

void IncidentCoordinator::notify(ResponseUnit *sender, std::string event)
{
    const std::string senderName = sender ? sender->getUnitName() : "<unknown>";
    std::cout << ColourHelper::B_YELLOW << "Coordinator event " << event
              << " From " << senderName << ColourHelper::RESET << std::endl;

    if (event == "security-dispatched")
    {
        for (ResponseUnit *unit : colleagues)
            if (unit != sender)
                unit->send("incident-active");
    }
    else if (event == "incident-active")
    {
        std::cout << ColourHelper::B_YELLOW << "Coordinator "
                  << senderName << " acknowledges active incident"
                  << ColourHelper::RESET << std::endl;
    }
    else if (event == "area-unsafe")
    {
        AreaComponent *unsafeArea = sender ? sender->getContextArea() : nullptr;

        ResponseUnit *fac = findColleague(colleagues, "Facilities");
        ResponseUnit *comms = findColleague(colleagues, "Comms");

        if (fac)
        {
            fac->setContextArea(unsafeArea);
            fac->handleCoordinatorEvent("secure-area", nullptr);
        }
        if (comms)
        {
            comms->handleCoordinatorEvent("broadcast-alert", nullptr);
        }
    }
    else if (event == "area-secured")
    {
        for (ResponseUnit *unit : colleagues)
            if (unit != sender)
                unit->send("area-secured");
    }
    else if (event == "facilities-dispatched")
    {
        for (ResponseUnit *unit : colleagues)
            if (unit != sender)
                unit->send("facilities-on-scene");
    }
    else if (event == "facilities-on-scene")
    {
        ResponseUnit *sec = findColleague(colleagues, "Security");
        if (sec)
            sec->handleCoordinatorEvent("escort-facilities", nullptr);
    }
    else if (event == "escort-active")
    {
        std::cout << ColourHelper::B_YELLOW << "Coordinator "
                  << senderName << " escort confirmed" << ColourHelper::RESET << std::endl;
    }
    else if (event == "medical-dispatched")
    {
        for (ResponseUnit *unit : colleagues)
            if (unit != sender)
                unit->send("medical-on-scene");
    }
    else if (event == "medical-on-scene")
    {
        ResponseUnit *sec = findColleague(colleagues, "Security");
        if (sec)
            sec->handleCoordinatorEvent("clear-path-medical", nullptr);
    }
    else if (event == "path-clear")
    {
        ResponseUnit *med = findColleague(colleagues, "Medical");
        if (med)
            med->handleCoordinatorEvent("path-clear", nullptr);
    }
    else if (event == "broadcast-alert")
    {
        std::cout << ColourHelper::B_YELLOW << "Coordinator " << senderName << " broadcast instruction acknowledged" << ColourHelper::RESET << std::endl;
    }
    else if (event == "secure-area")
    {
        std::cout << ColourHelper::B_YELLOW << "Coordinator " << senderName << " secure-area acknowledged" << ColourHelper::RESET << std::endl;
    }
    else if (event == "incident-dispatched" || event == "incident-in-progress" || event == "incident-resolved" || event == "incident-closed")
    {
    }
    else
    {
        std::cout << ColourHelper::B_YELLOW << "Coordinator no reaction " << "configured for " << event << ColourHelper::RESET << std::endl;
    }
}

void IncidentCoordinator::dispatchAll(Incident *incident)
{
    if (!incident)
        return;
    std::cout << ColourHelper::B_YELLOW << "Coordinator dispatching all registered units for incident (" << incident->getIncidentId() << ")" << ColourHelper::RESET << std::endl;
    for (ResponseUnit *unit : colleagues)
        unit->dispatch(incident);
}

void IncidentCoordinator::onIncidentStateChanged(Incident *incident, const std::string &oldState, const std::string &newState)
{
    if (!incident)
        return;

    std::cout << ColourHelper::B_YELLOW
              << "Coordinator Incident (" << incident->getIncidentId()
              << ") transitioned: " << oldState << " -> " << newState
              << ColourHelper::RESET << std::endl;

    std::string event;
    if (newState == "Dispatched State")
        event = "incident-dispatched";
    else if (newState == "In Progress State")
        event = "incident-in-progress";
    else if (newState == "Resolve State")
        event = "incident-resolved";
    else if (newState == "Closed State")
        event = "incident-closed";
    else
        return;

    for (ResponseUnit *unit : colleagues)
        unit->send(event);
}