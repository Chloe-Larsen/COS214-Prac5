#pragma once
#include <string>

class SecurityTeam;
class FacilitiesStaff;
class AlertSystem;
class Incident;

// Facade: gives the operator one call for a realistic multi-step workflow
// (dispatch security, lock the area, raise an alert) instead of making the
// client call three subsystems itself. The subsystem parts remain usable on
// their own too (see main.cpp calling FacilitiesStaff::unlockArea directly).
class CampusGuardFacade {
public:
    CampusGuardFacade(SecurityTeam* security, FacilitiesStaff* facilities, AlertSystem* alerts);

    void declareEmergency(Incident& incident);

private:
    SecurityTeam* security;     // non-owning
    FacilitiesStaff* facilities; // non-owning
    AlertSystem* alerts;         // non-owning
};
