#ifndef INCIDENTCOORDINATOR_H
#define INCIDENTCOORDINATOR_H

#include "ResponseMediator.h"
#include <vector>
#include "Incident.h"
#include "ResponseUnit.h"

class IncidentCoordinator : public ResponseMediator, public IncidentObserver
{
private:
	std::vector<ResponseUnit *> colleagues;

public:
	IncidentCoordinator();
	~IncidentCoordinator();
	void registerColleague(ResponseUnit *unit);
	void notify(ResponseUnit *sender, std::string event) override;
	void dispatchAll(Incident *incident);
	void onIncidentStateChanged(Incident *incident, const std::string &oldState, const std::string &newState) override;
};

#endif
