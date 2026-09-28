#include "../include/SecurityTeam.h"

SecurityTeam::SecurityTeam(std::string unitName) : ResponseUnit(nullptr, unitName)
{
    std::cout << ColourHelper::RED << "New security team " << unitName << " has been created" << ColourHelper::RESET << std::endl;
}

SecurityTeam::~SecurityTeam()
{
}

void SecurityTeam::dispatch(Incident *incident)
{
    if (!incident)
        return;
    std::cout << ColourHelper::RED << "Security Team " << unitName << " responding to Incident(" << incident->getIncidentId() << ")" << ColourHelper::RESET << std::endl;
    send("security-dispatched");
}

void SecurityTeam::reportUnsafeArea(AreaComponent *area)
{
    if (!area)
        return;
    lastUnsafeArea = area;
    std::cout << ColourHelper::B_YELLOW << "Security Team " << unitName << " has reported at area " << area->getName() << " is unsafe" << ColourHelper::RESET << std::endl;
    send("area-unsafe");
}


void SecurityTeam::handleCoordinatorEvent(const std::string &event, Incident *incident)
{
    if (!incident)
        return;

    if (event == "escort-facilities")
    {
        std::cout << ColourHelper::B_YELLOW << "Security Team " << unitName     << " is escorting Facilities into Incident(" << incident->getIncidentId() << ")" << ColourHelper::RESET << std::endl;
        send("escort-active");
    }
    else if (event == "clear-path-medical")
    {
        std::cout << ColourHelper::B_YELLOW << "Security Team " << unitName << " is clearing a path for Medical at Incident(" << incident->getIncidentId() << ")" << ColourHelper::RESET << std::endl;
        send("path-clear");
    }
    else if (event == "stand-down")
    {
        std::cout << ColourHelper::B_YELLOW << "Security Team " << unitName << " stands down for Incident(" << incident->getIncidentId() << ")" << ColourHelper::RESET << std::endl;
    }
}

AreaComponent *SecurityTeam::getContextArea() const
{
    return lastUnsafeArea;
}