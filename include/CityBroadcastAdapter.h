#ifndef CITYBROADCASTADAPTER_H
#define CITYBROADCASTADAPTER_H

#include "LegacyCityBroadcastSystem.h"
#include "ExternalAlertService.h"
class CityBroadcastAdapter : ExternalAlertService
{
private:
	LegacyCityBroadcastSystem* legacySystem;
public:
	CityBroadcastAdapter(LegacyCityBroadcastSystem *legacy);
	~CityBroadcastAdapter();
	void sendAlert(std::string message, int level);
};

#endif
