#ifndef INCIDENT_H
#define INCIDENT_H

#include <string>
#include "IncidentState.h"
#include "ColourHelper.h"
class Incident {
private:
	std::string incidentId;
	std::string location;
	std::string description;
	int severity;
	IncidentState* currentState;

public:
	Incident(std::string incidentId, std::string location, std::string description, int severity, IncidentState* currentState);
	~Incident();
	void setState(IncidentState* state);
	void dispatch();
	void resolve();
	void close();
	void cancel();
	std::string getStatusName();
};

#endif
