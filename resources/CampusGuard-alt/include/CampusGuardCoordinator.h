#pragma once
#include "ResponseMediator.h"
#include "IncidentObserver.h"
#include <string>

class SecurityTeam;
class MedicalTeam;
class FacilitiesStaff;

// ConcreteMediator: coordinates SecurityTeam, MedicalTeam and FacilitiesStaff
// so they never need to reference each other directly.
// Also implements IncidentObserver so it reacts to incident status changes.
class CampusGuardCoordinator : public ResponseMediator, public IncidentObserver {
public:
    CampusGuardCoordinator(SecurityTeam* security, MedicalTeam* medical, FacilitiesStaff* facilities);

    void notify(ResponseComponent* sender, const std::string& event) override;
    void onIncidentStatusChanged(const Incident& incident) override;

private:
    // non-owning: colleagues are owned by whoever assembles the application (see main)
    SecurityTeam* security;
    MedicalTeam* medical;
    FacilitiesStaff* facilities;
};
