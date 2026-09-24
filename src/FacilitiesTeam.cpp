#include "../include/FacilitiesTeam.h"

FacilitiesTeam::FacilitiesTeam(std::string unitName) : ResponseUnit(nullptr, unitName)
{
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