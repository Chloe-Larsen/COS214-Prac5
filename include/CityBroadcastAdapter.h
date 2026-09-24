#ifndef CITYBROADCASTADAPTER_H
#define CITYBROADCASTADAPTER_H

#include "LegacyCityBroadcastSystem.h"
#include "ExternalAlertService.h"
class CityBroadcastAdapter : public ExternalAlertService
{
private:
	LegacyCityBroadcastSystem* legacySystem;
public:
	CityBroadcastAdapter();
	~CityBroadcastAdapter();
	void sendAlert(std::string message, int level) override;
};

#endif
