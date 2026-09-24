#ifndef INCIDENTSTATE_H
#define INCIDENTSTATE_H

#include <string>
#include "ColourHelper.h"

class Incident; 

class IncidentState
{
public:
	IncidentState();
	virtual ~IncidentState();
	virtual void continueProcess(Incident *incident) = 0;
	virtual void dispatch(Incident *incident) = 0;
	virtual void resolve(Incident *incident) = 0;
	virtual void close(Incident *incident) = 0;
	virtual void cancel(Incident *incident) = 0;
	virtual std::string getStatusName() const = 0;
};

#endif
