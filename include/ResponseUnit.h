#ifndef RESPONSEUNIT_H
#define RESPONSEUNIT_H

#include <string>
#include "ResponseMediator.h"

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
};

#endif
