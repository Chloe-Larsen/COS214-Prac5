#ifndef RESPONSEUNIT_H
#define RESPONSEUNIT_H

#include <string>
#include "ResponseMediator.h"
#include "AreaComponent.h"
class Incident;

class ResponseUnit
{
protected:
	ResponseMediator *mediator;
	std::string unitName;

public:
	ResponseUnit(ResponseMediator *mediator, std::string unitName);
	virtual ~ResponseUnit();
	void setMediator(ResponseMediator *mediator);
	void send(std::string event);
	virtual void dispatch(Incident *incident) = 0;
	std::string getUnitName() const;
	virtual void handleCoordinatorEvent(const std::string &, Incident *);
	virtual void setContextArea(AreaComponent *) {}
	virtual AreaComponent *getContextArea() const { return nullptr; }
};

#endif
