#ifndef AREA_H
#define AREA_H

#include "AreaComponent.h"

class Area : AreaComponent
{
private:
	bool isLocked;

public:
	Area(std::string name);
	~Area();
	void lock();
	void unlock();
	void restrict();
};

#endif
