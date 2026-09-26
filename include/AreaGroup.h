#ifndef AREAGROUP_H
#define AREAGROUP_H
#include "AreaComponent.h"

class AreaGroup : public AreaComponent
{
private:
	std::vector<AreaComponent *> children;
public:
	AreaGroup(std::string name);
	~AreaGroup();
	void lock() override;
	void unlock() override;
	void restrict() override;
	void add(AreaComponent *component);
	void remove(AreaComponent *component);
};

#endif
