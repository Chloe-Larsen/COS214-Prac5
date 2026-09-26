#ifndef LOCKAREACOMMAND_H
#define LOCKAREACOMMAND_H

#include "AreaComponent.h"
#include "Command.h"

class LockAreaCommand : public Command {
private:
	AreaComponent* receiver;
public:
	LockAreaCommand(AreaComponent* receiver);
	~LockAreaCommand();
	void execute() override;
	void undo() override;
};

#endif
