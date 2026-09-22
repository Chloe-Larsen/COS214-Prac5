#ifndef RESOLVEDSTATE_H
#define RESOLVEDSTATE_H

#include "IncidentState.h"
class ResolvedState : IncidentState
{
public:
	ResolvedState();
	void dispatch(Incident *incident);
	void resolve(Incident *incident);
	void close(Incident *incident);
	void cancel(Incident *incident);
	std::string getStatusName();
};

#endif
