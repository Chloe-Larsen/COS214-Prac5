#ifndef FACILITIESTEAM_H
#define FACILITIESTEAM_H

#include "ResponseUnit.h"
#include "Incident.h"
#include "AreaComponent.h"

class FacilitiesTeam : ResponseUnit
{

public:
	FacilitiesTeam(std::string unitName);
	void dispatch(Incident *incident);
	void secureArea(AreaComponent *area);
};

#endif
