#ifndef INPROGRESSSTATE_H
#define INPROGRESSSTATE_H

#include "IncidentState.h"
class InProgressState : IncidentState {
public:
	InProgressState();
	void dispatch(Incident *incident);
	void resolve(Incident *incident);
	void close(Incident *incident);
	void cancel(Incident *incident);
	std::string getStatusName();
};

#endif
