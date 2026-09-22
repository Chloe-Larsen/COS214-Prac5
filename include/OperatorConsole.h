#ifndef OPERATORCONSOLE_H
#define OPERATORCONSOLE_H

#include "Command.h"
#include <vector>
#include "ColourHelper.h"

class OperatorConsole
{
private:
	std::vector<Command *> history;
public:
	OperatorConsole();
	~OperatorConsole();
	void executeCommand(Command *command);
	void undoLast();
};

#endif
