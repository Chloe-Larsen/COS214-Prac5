#include "CampusGuardCoordinator.h"
#include "SecurityTeam.h"
#include "MedicalTeam.h"
#include "FacilitiesStaff.h"
#include "Incident.h"
#include <iostream>

CampusGuardCoordinator::CampusGuardCoordinator(SecurityTeam* security_, MedicalTeam* medical_,
                                                 FacilitiesStaff* facilities_)
    : security(security_), medical(medical_), facilities(facilities_) {}

void CampusGuardCoordinator::notify(ResponseComponent* sender, const std::string& event) {
    std::cout << "[Coordinator] received " << event << " from " << sender->getName() << "\n";

    // This is the actual point of Mediator: one colleague's action drives another's,
    // and neither colleague needs to know about the other.
    if (event == "SECURITY_DISPATCHED" && sender == static_cast<ResponseComponent*>(security)) {
        std::cout << "[Coordinator] security on scene -> requesting facilities lockdown\n";
        facilities->lockArea("affected zone");
    } else if (event == "AREA_LOCKED" && sender == static_cast<ResponseComponent*>(facilities)) {
        std::cout << "[Coordinator] area secured -> clearing medical to approach\n";
        medical->treatAt("affected zone");
    }
}

void CampusGuardCoordinator::onIncidentStatusChanged(const Incident& incident) {
    std::cout << "[Coordinator] observed incident " << incident.getId()
               << " is now " << toString(incident.getStatus()) << "\n";
}
