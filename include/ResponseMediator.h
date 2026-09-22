#ifndef RESPONSEMEDIATOR_H
#define RESPONSEMEDIATOR_H

#include "ResponseUnit.h"
#include "ColourHelper.h"

class ResponseMediator
{
public:
	ResponseMediator();
	virtual ~ResponseMediator();
	virtual void notify(ResponseUnit *sender, std::string event) = 0;
};

#endif
