#ifndef COMMUNICATIONSERVICE_H
#define COMMUNICATIONSERVICE_H

#include "ResponseUnit.h"
#include "ExternalAlertService.h"

class CommunicationService : public ResponseUnit
{
private:
	ExternalAlertService *alertService;
public:
	CommunicationService(std::string unitName, ExternalAlertService *alertService);
	~CommunicationService();
	void sendAlert(std::string message, int level);
	void broadcastExternally(std::string message, int level);
	void dispatch(Incident *incident) override;
	void handleCoordinatorEvent(const std::string &event, Incident *incident) override;
};

#endif
