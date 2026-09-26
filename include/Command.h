#ifndef COMMAND_H
#define COMMAND_H

#include "ColourHelper.h"
class Command
{
public:
	Command();
	virtual ~Command();
	virtual void execute() = 0;
	virtual void undo() = 0;
};

#endif
