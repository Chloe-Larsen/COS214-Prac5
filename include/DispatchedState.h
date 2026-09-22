#ifndef DISPATCHEDSTATE_H
#define DISPATCHEDSTATE_H

#include "IncidentState.h"
class DispatchedState : IncidentState
{
public:
	DispatchedState();
	void dispatch(Incident *incident);
	void resolve(Incident *incident);
	void close(Incident *incident);
	void cancel(Incident *incident);
	std::string getStatusName();
};

#endif
