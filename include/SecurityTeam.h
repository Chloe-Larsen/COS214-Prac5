#ifndef SECURITYTEAM_H
#define SECURITYTEAM_H

#include "ResponseUnit.h"
#include "Incident.h"
#include "AreaComponent.h"

class SecurityTeam : public ResponseUnit
{
private:
	AreaComponent *lastUnsafeArea = nullptr;
public:
	SecurityTeam(std::string unitName);
	~SecurityTeam();
	void dispatch(Incident *incident) override;
	void reportUnsafeArea(AreaComponent *area);
	void handleCoordinatorEvent(const std::string &event, Incident *incident) override;
	AreaComponent *getContextArea() const override;
};

#endif
