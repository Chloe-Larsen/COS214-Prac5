#ifndef INCIDENT_H
#define INCIDENT_H

#include <string>
#include <vector>
#include <algorithm>
#include "IncidentState.h"
#include "ColourHelper.h"
#include "IncidentObserver.h"
class Incident
{
private:
	std::string incidentId;
	std::string location;
	std::string description;
	int severity;
	IncidentState *currentState;
	std::vector<IncidentObserver *> observers;
	void notifyObservers(const std::string &oldState, const std::string &newState);

public:
	Incident(std::string incidentId, std::string location, std::string description, int severity);
	~Incident();
	void setState(IncidentState *state);
	void continueProcess();
	void dispatch();
	void resolve();
	void close();
	void cancel();
	std::string getStatusName() const;
	std::string getIncidentId() const;
	void addObserver(IncidentObserver *observer);
	void removeObserver(IncidentObserver *observer);
};

#endif
