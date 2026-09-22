#ifndef EXTERNALALERTSERVICE_H
#define EXTERNALALERTSERVICE_H

#include <string>
#include "ColourHelper.h"

class ExternalAlertService
{
public:
	ExternalAlertService();
	virtual ~ExternalAlertService();
	virtual void sendAlert(std::string message, int level) = 0;
};

#endif
