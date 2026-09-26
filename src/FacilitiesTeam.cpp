#include "../include/FacilitiesTeam.h"

FacilitiesTeam::FacilitiesTeam(std::string unitName) : ResponseUnit(nullptr, unitName)
{
    std::cout << ColourHelper::RED << "New facilities team " << unitName << " has been created" << ColourHelper::RESET << std::endl;
}

FacilitiesTeam::~FacilitiesTeam()
{
}

void FacilitiesTeam::dispatch(Incident *incident)
{
    if (!incident)
        return;
    std::cout << ColourHelper::RED << "Facilities Team " << unitName << " responding to Incident(" << incident->getIncidentId() << ")" << ColourHelper::RESET << std::endl;
    send("facilities-dispatched");
}

void FacilitiesTeam::secureArea(AreaComponent *area)
{
    if (!area)
        return;
    area->lock();
    std::cout << ColourHelper::B_YELLOW << "Facilities Team " << unitName << " secured area " << area->getName() << ColourHelper::RESET << std::endl;
    send("area-secured");
}

void FacilitiesTeam::handleCoordinatorEvent(const std::string &event, Incident *incident)
{
    if (!incident)
        return;

    if (event == "secure-area")
    {
        std::cout << ColourHelper::B_YELLOW << "Facilities Team " << unitName
                  << " is securing the reported area for Incident("
                  << incident->getIncidentId() << ")" << ColourHelper::RESET << std::endl;
        if (pendingArea)
            secureArea(pendingArea);
        else
            send("area-secured");
    }
    else if (event == "stand-down")
    {
        std::cout << ColourHelper::B_YELLOW << "Facilities Team " << unitName
                  << " stands down for Incident("
                  << incident->getIncidentId() << ")" << ColourHelper::RESET << std::endl;
    }
}