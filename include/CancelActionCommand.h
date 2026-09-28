	#ifndef CANCELACTIONCOMMAND_H
#define CANCELACTIONCOMMAND_H

#include "Command.h"
#include "Incident.h"

class CancelActionCommand : public Command
{
private:
	Incident* targetIncident;
public:
	CancelActionCommand(Incident *targetIncident);
	~CancelActionCommand();
	void execute() override;
	void undo() override;
};

#endif
