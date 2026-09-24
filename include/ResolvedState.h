#ifndef RESOLVEDSTATE_H
#define RESOLVEDSTATE_H

#include "IncidentState.h"
#include "Incident.h"
class ResolvedState : public IncidentState
{
public:
	ResolvedState();
	void continueProcess(Incident* incident) override;
	void dispatch(Incident *incident) override;
	void resolve(Incident *incident) override;
	void close(Incident *incident) override;
	void cancel(Incident *incident) override;
	std::string getStatusName() const override;
};

#endif
