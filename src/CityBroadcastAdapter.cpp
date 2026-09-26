#include "../include/CityBroadcastAdapter.h"

CityBroadcastAdapter::CityBroadcastAdapter() : ExternalAlertService(), legacySystem(new LegacyCityBroadcastSystem())
{
    std::cout << ColourHelper::B_GREEN << "New city broadcast adapter has been created" << ColourHelper::RESET << std::endl;
}

CityBroadcastAdapter::~CityBroadcastAdapter()
{
    if (legacySystem != nullptr)
        delete legacySystem;
}

void CityBroadcastAdapter::sendAlert(std::string message, int level)
{
    int priorityCode = level;
    int emergencyCode = 100;

    legacySystem->broadcastEmergency(emergencyCode, message, priorityCode);
}