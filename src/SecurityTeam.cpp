#include "../include/SecurityTeam.h"

SecurityTeam::SecurityTeam(std::string unitName) : ResponseUnit(nullptr, unitName)
{
}

SecurityTeam::~SecurityTeam()
{
}

void SecurityTeam::dispatch(Incident *incident)
{
    if (!incident)
        return;
    std::cout << ColourHelper::RED << "Security Team " << unitName << " responding  to Incident(" << incident->getIncidentId() << ")"  << ColourHelper::RESET << std::endl;
    send("security-dispatched");
}

void SecurityTeam::reportUnsafeArea(AreaComponent *area)
{
    if(!area)
        return;
    
    std::cout << ColourHelper::B_YELLOW << "Security Team " << unitName << " has reported at area " << area->getName() << " is unsafe" << ColourHelper::RESET << std::endl;
    send("area-unsafe");
}
