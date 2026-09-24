#include "../include/LegacyCityBroadcastSystem.h"

LegacyCityBroadcastSystem::LegacyCityBroadcastSystem()
{
}

LegacyCityBroadcastSystem::~LegacyCityBroadcastSystem()
{
}

void LegacyCityBroadcastSystem::broadcastEmergency(int code, std::string text, int priorityLevel)
{
    std::cout << ColourHelper::B_GREEN << "CITY LEGACY BROADCAST \n code = " << code << "\npriority = " << priorityLevel << "\ntext:" << text << ColourHelper::RESET << std::endl;
}