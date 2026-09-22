#ifndef AREACOMPONENT_H
#define AREACOMPONENT_H

#include "ColourHelper.h"
#include <string>
#include <iostream>
#include <vector>

class AreaComponent
{
private:
	std::string name;
public:
	AreaComponent(std::string name);
	virtual ~AreaComponent();
	virtual void lock() = 0;
	virtual void unlock() = 0;
	virtual void restrict() = 0;
	std::string getName();
};

#endif
