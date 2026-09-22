#ifndef ISSUEALERTCOMMAND_H
#define ISSUEALERTCOMMAND_H

#include "Command.h"
#include "CommunicationService.h"

class IssueAlertCommand : Command {

private:
	CommunicationService* receiver;
	std::string message;

public:
	IssueAlertCommand(CommunicationService* receiver, std::string message);
	~IssueAlertCommand();
	void execute();
	void undo();
};

#endif
