#include "../include/AreaComponent.h"

AreaComponent::AreaComponent(std::string name) : name(name)
{
}

AreaComponent::~AreaComponent()
{
}

std::string AreaComponent::getName()
{
	return this->name;
}