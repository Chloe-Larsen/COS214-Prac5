#ifndef INCIDENTCOORDINATOR_H
#define INCIDENTCOORDINATOR_H

#include "ResponseMediator.h"
#include <vector>
#include "Incident.h"

class IncidentCoordinator : public ResponseMediator
{
private:
	std::vector<ResponseUnit *> colleagues;
public:
	IncidentCoordinator();
	~IncidentCoordinator();
	void registerColleague(ResponseUnit *unit);
	void notify(ResponseUnit *sender, std::string event) override;
	void dispatchAll(Incident * incident);
};

#endif
