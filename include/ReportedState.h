#ifndef REPORTEDSTATE_H
#define REPORTEDSTATE_H

#include "IncidentState.h"

class ReportedState : IncidentState
{
public:
	ReportedState();
	void dispatch(Incident *incident);
	void resolve(Incident *incident);
	void close(Incident *incident);
	void cancel(Incident *incident);
	std::string getStatusName();
};

#endif
