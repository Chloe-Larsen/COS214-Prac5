#ifndef AREA_H
#define AREA_H

#include "AreaComponent.h"

class Area : public AreaComponent
{
private:
	bool isLocked;

public:
	Area(std::string name);
	~Area();
	void lock() override;
	void unlock() override;
	void restrict() override;
};

#endif
