#include "../include/EmergencyResponseFacade.h"

EmergencyResponseFacade::EmergencyResponseFacade(IncidentCoordinator *coordinator, ExternalAlertService *alertService) : coordinator(coordinator), alertService(alertService)
{
}

EmergencyResponseFacade::~EmergencyResponseFacade()
{
}

void EmergencyResponseFacade::initiateLockdown(Incident *incident, AreaComponent *area)
{
    if (!incident || !area)
    {
        std::cout << ColourHelper::MAGENTA << "Facade initiate lockdown called with a null incident or area." << std::endl;
        return;
    }

    std::cout << ColourHelper::MAGENTA << "===== LOCKDOWN INITIATED for incident " << incident->getIncidentId() << " (" << incident->getStatusName() << ") =====" << ColourHelper::RESET << std::endl;

    std::cout << ColourHelper::MAGENTA << ColourHelper::UNDERLINE << "Facade step 1: " << ColourHelper::RESET << ColourHelper::MAGENTA << "locking area " << area->getName() << ColourHelper::RESET << std::endl;
    area->lock();

    std::cout << ColourHelper::MAGENTA << ColourHelper::UNDERLINE << "\nFacade step 2: " << ColourHelper::RESET << ColourHelper::MAGENTA << "dispatching response units via coordinator" << ColourHelper::RESET << std::endl;
    if (coordinator)
    {
        coordinator->dispatchAll(incident);
    }
    else
    {
        std::cout << ColourHelper::MAGENTA << "No coordinator configured; dispatch skipped." << std::endl;
    }

    std::cout << ColourHelper::MAGENTA << ColourHelper::UNDERLINE << "\nFacade step 3: " << ColourHelper::RESET << ColourHelper::MAGENTA << "advancing incident state" << ColourHelper::RESET << std::endl;
    incident->dispatch();

    std::cout << ColourHelper::MAGENTA << ColourHelper::UNDERLINE << "\nFacade step 4: " << ColourHelper::RESET << ColourHelper::MAGENTA << "raising external alert" << ColourHelper::RESET << std::endl;
    if (alertService)
    {
        alertService->sendAlert("Lockdown in progress for incident " + incident->getIncidentId() + " at " + area->getName(), 4);
    }
    else
    {
        std::cerr << "Facade no alert service configured; external alert skipped.\n";
    }

    std::cout << ColourHelper::MAGENTA << "===== LOCKDOWN WORKFLOW COMPLETE =====" << ColourHelper::RESET << std::endl;
}