#ifndef RESPONSEMEDIATOR_H
#define RESPONSEMEDIATOR_H

#include "ColourHelper.h"

class ResponseUnit;
class ResponseMediator
{
public:
	ResponseMediator();
	virtual ~ResponseMediator();
	virtual void notify(ResponseUnit *sender, std::string event) = 0;
};

#endif
