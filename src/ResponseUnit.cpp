#include "../include/ResponseUnit.h"

void ResponseUnit::setMediator(ResponseMediator *mediator)
{
	this->mediator = mediator;
}

ResponseUnit::~ResponseUnit()
{
}

void ResponseUnit::send(std::string event)
{
}

ResponseUnit::ResponseUnit(ResponseMediator *mediator, std::string unitName)
{
}
