#ifndef EMERGENCYRESPONSEFACADE_H
#define EMERGENCYRESPONSEFACADE_H

#include "IncidentCoordinator.h"
#include "ExternalAlertService.h"
#include "Incident.h"
#include "AreaComponent.h"
#include "ColourHelper.h"

class EmergencyResponseFacade
{
private:
	IncidentCoordinator *coordinator;
	ExternalAlertService *alertService;
public:
	EmergencyResponseFacade(IncidentCoordinator *coordinator, ExternalAlertService *alertService);
	~EmergencyResponseFacade();
	void initiateLockdown(Incident *incident, AreaComponent *area);
};

#endif
