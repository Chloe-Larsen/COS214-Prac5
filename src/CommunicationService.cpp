#include "../include/CommunicationService.h"
#include "../include/Incident.h"

CommunicationService::CommunicationService(std::string unitName, ExternalAlertService *alertService) : ResponseUnit(nullptr, unitName), alertService(alertService)
{
    std::cout << ColourHelper::RED << "New communication service " << unitName << " has been created" << ColourHelper::RESET << std::endl;
}

CommunicationService::~CommunicationService()
{
}

void CommunicationService::sendAlert(std::string message, int level)
{
    std::cout << ColourHelper::B_YELLOW << "Communication Service " << unitName << " issuing on-campus alert: " << message << " (level " << level << ")" << ColourHelper::RESET << std::endl;
    broadcastExternally(message, level);
}

void CommunicationService::broadcastExternally(std::string message, int level)
{
    if (!alertService)
    {
        std::cout << ColourHelper::B_YELLOW << "Communication Service has no ExternalAlertService configured" << ColourHelper::RESET << std::endl;
        return;
    }
    alertService->sendAlert(message, level);
}

void CommunicationService::dispatch(Incident *incident)
{
    std::cout << ColourHelper::B_YELLOW << "Communication Service " << unitName << " has no dispatch role for Incident(" << incident->getIncidentId() << ")" << ColourHelper::RESET << std::endl;
}

void CommunicationService::handleCoordinatorEvent(const std::string &event, Incident *incident)
{
    if (!incident)
        return;
    if (event == "broadcast-alert")
    {
        std::string msg = "Area unsafe for Incident(" + incident->getIncidentId() + "). Public advisory issued.";
        sendAlert(msg, 3);
    }
    else if (event == "stand-down")
    {
        std::cout << ColourHelper::B_YELLOW << "Communication Service " << unitName
                  << " stands down for Incident("
                  << incident->getIncidentId() << ")" << ColourHelper::RESET << std::endl;
    }
}