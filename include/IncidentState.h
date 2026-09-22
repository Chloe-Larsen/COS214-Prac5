#ifndef INCIDENTSTATE_H
#define INCIDENTSTATE_H

#include "Incident.h"
#include <string>
#include "ColourHelper.h"

class IncidentState
{
public:
	IncidentState();
	virtual ~IncidentState();
	virtual void dispatch(Incident *incident) = 0;
	virtual void resolve(Incident *incident) = 0;
	virtual void close(Incident *incident) = 0;
	virtual void cancel(Incident *incident) = 0;
	virtual std::string getStatusName() = 0;
};

#endif
