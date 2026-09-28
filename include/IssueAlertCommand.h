#ifndef ISSUEALERTCOMMAND_H
#define ISSUEALERTCOMMAND_H

#include "Command.h"
#include "CommunicationService.h"

class IssueAlertCommand : public Command {

private:
	CommunicationService* receiver;
	std::string message;
	int level;

public:
	IssueAlertCommand(CommunicationService* receiver, std::string message, int level);
	~IssueAlertCommand();
	void execute() override;
	void undo() override;
};

#endif
