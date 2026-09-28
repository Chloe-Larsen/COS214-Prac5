#ifndef LEGACYCITYBROADCASTSYSTEM_H
#define LEGACYCITYBROADCASTSYSTEM_H

#include <string>
#include "ColourHelper.h"

class LegacyCityBroadcastSystem
{
public:
	LegacyCityBroadcastSystem();
	~LegacyCityBroadcastSystem();
	void broadcastEmergency(int code, std::string text, int priorityLevel);
};

#endif
