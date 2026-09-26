#ifndef DISPATCHUNITCOMMAND_H
#define DISPATCHUNITCOMMAND_H

#include "Command.h"
#include "Incident.h"
#include "ResponseUnit.h"

class DispatchUnitCommand : public Command
{
private:
	ResponseUnit *receiver;
	Incident *targetIncident;

public:
	DispatchUnitCommand(ResponseUnit *receiver, Incident *targetIncident);
	~DispatchUnitCommand();
	void execute() override;
	void undo() override;
};

#endif
