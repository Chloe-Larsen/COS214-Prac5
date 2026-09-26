#ifndef FACILITIESTEAM_H
#define FACILITIESTEAM_H

#include "ResponseUnit.h"
#include "Incident.h"
#include "AreaComponent.h"

class FacilitiesTeam : public ResponseUnit
{
private:
	AreaComponent *pendingArea = nullptr;
public:
	FacilitiesTeam(std::string unitName);
	~FacilitiesTeam();
	void dispatch(Incident *incident) override;
	void secureArea(AreaComponent *area);
	void handleCoordinatorEvent(const std::string &event, Incident *incident) override;
	void setPendingArea(AreaComponent *area) { pendingArea = area; }
	void setContextArea(AreaComponent *area) override { pendingArea = area; }
};

#endif
