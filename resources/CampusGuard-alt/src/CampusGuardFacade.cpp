#include "CampusGuardFacade.h"
#include "SecurityTeam.h"
#include "FacilitiesStaff.h"
#include "AlertSystem.h"
#include "Incident.h"
#include <iostream>

CampusGuardFacade::CampusGuardFacade(SecurityTeam* security_, FacilitiesStaff* facilities_,
                                       AlertSystem* alerts_)
    : security(security_), facilities(facilities_), alerts(alerts_) {}

void CampusGuardFacade::declareEmergency(Incident& incident) {
    std::cout << "[CampusGuardFacade] declaring emergency for incident " << incident.getId() << "\n";
    security->dispatchTo(incident.getLocation());
    facilities->lockArea(incident.getLocation());
    alerts->sendAlert("evacuate " + incident.getLocation());
    incident.setStatus(IncidentStatus::DISPATCHED);
}
