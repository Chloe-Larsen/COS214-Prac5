#ifndef AREAGROUP_H
#define AREAGROUP_H
#include "AreaComponent.h"

class AreaGroup : AreaComponent
{
private:
	std::vector<AreaComponent *> children;
public:
	AreaGroup(std::string name);
	~AreaGroup();
	void lock();
	void unlock();
	void restrict();
	void add(AreaComponent *component);
	void remove(AreaComponent *component);
};

#endif
