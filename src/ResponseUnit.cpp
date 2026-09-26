#include "../include/ResponseUnit.h"

ResponseUnit::ResponseUnit(ResponseMediator *mediator, std::string unitName) : mediator(mediator), unitName(unitName)
{
}

ResponseUnit::~ResponseUnit()
{	
}

void ResponseUnit::setMediator(ResponseMediator *mediator)
{
	this->mediator = mediator;
}

void ResponseUnit::send(std::string event)
{
	if(mediator)	
		mediator->notify(this, event);	
	else
		std::cout << ColourHelper::B_YELLOW << unitName << " does not have a mediator." << ColourHelper::RESET << std::endl;
}

std::string ResponseUnit::getUnitName() const
{
	return unitName;
}