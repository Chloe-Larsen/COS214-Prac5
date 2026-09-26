#ifndef FACILITIESTEAM_H
#define FACILITIESTEAM_H

#include "ResponseUnit.h"
#include "Incident.h"
#include "AreaComponent.h"

class FacilitiesTeam : public ResponseUnit
{

public:
	FacilitiesTeam(std::string unitName);
	~FacilitiesTeam();
	void dispatch(Incident *incident) override;
	void secureArea(AreaComponent *area);
};

#endif
