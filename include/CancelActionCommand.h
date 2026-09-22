#ifndef CANCELACTIONCOMMAND_H
#define CANCELACTIONCOMMAND_H

#include "Command.h"
#include "Incident.h"

class CancelActionCommand : Command
{
private:
	Incident* targetIncident;
public:
	CancelActionCommand(Incident *targetIncident);
	~CancelActionCommand();
	void execute();
	void undo();
};

#endif
