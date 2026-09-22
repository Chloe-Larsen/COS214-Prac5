#ifndef CLOSEDSTATE_H
#define CLOSEDSTATE_H

#include "IncidentState.h"

class ClosedState : IncidentState
{
public:
	ClosedState();
	void dispatch(Incident *incident);
	void resolve(Incident *incident);
	void close(Incident *incident);
	void cancel(Incident *incident);
	std::string getStatusName();
};

#endif
