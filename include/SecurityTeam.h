#ifndef SECURITYTEAM_H
#define SECURITYTEAM_H

#include "ResponseUnit.h"
#include "Incident.h"
#include "AreaComponent.h"

class SecurityTeam : ResponseUnit
{
public:
	SecurityTeam(std::string unitName);
	~SecurityTeam();
	void dispatch(Incident *incident);
	void reportUnsafeArea(AreaComponent *area);
};

#endif
