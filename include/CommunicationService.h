#ifndef COMMUNICATIONSERVICE_H
#define COMMUNICATIONSERVICE_H

#include "ResponseUnit.h"
#include "ExternalAlertService.h"

class CommunicationService : ResponseUnit
{
private:
	ExternalAlertService *alertService;
public:
	CommunicationService(std::string unitName);
	~CommunicationService();
	void sendAlert(std::string message, int level);
	void broadcastExternally(std::string message, int level);
};

#endif
