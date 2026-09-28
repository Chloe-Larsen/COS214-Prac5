#include "Incident.h"
#include "CampusGuardCoordinator.h"
#include "SecurityTeam.h"
#include "MedicalTeam.h"
#include "FacilitiesStaff.h"
#include "DispatchStrategy.h"
#include "LegacyAlarmSystem.h"
#include "LegacyAlertAdapter.h"
#include "CampusGuardFacade.h"
#include "OperatorConsole.h"
#include "Commands.h"
#include <iostream>
#include <memory>

// -----------------------------------------------------------------------
// Scenario 1: an incident reported and handled step-by-step through the
// OperatorConsole, showing Command driving Mediator coordination between
// colleagues, with Observer reporting status changes as they happen.
// Patterns visible: Command, Mediator, Strategy, Observer.
// -----------------------------------------------------------------------
void runScenarioOne() {
    std::cout << "\n===== Scenario 1: Reported break-in, Library Building =====\n";

    Incident incident("INC-1001", "Library Building", "Reported break-in, west entrance");

    SecurityTeam security("Alpha Patrol", nullptr, std::unique_ptr<DispatchStrategy>(new NearestUnitStrategy()));
    MedicalTeam medical("Medic Team 2", nullptr);
    FacilitiesStaff facilities("Facilities Crew A", nullptr);

    CampusGuardCoordinator coordinator(&security, &medical, &facilities);
    incident.attach(&coordinator);
    security.setMediator(&coordinator);
    medical.setMediator(&coordinator);
    facilities.setMediator(&coordinator);

    OperatorConsole console;
    console.issueCommand(std::unique_ptr<Command>(new DispatchUnitCommand(&security, &incident)));
    // DispatchUnitCommand triggers SecurityTeam::dispatchTo, which notifies the
    // mediator, which in turn locks facilities and clears medical -- one
    // Command call, three colleagues coordinated through the Mediator.

    console.cancelLast();
}

// -----------------------------------------------------------------------
// Scenario 2: a full emergency declared through the Facade, which itself
// reaches an external legacy alarm system through the Adapter.
// Patterns visible: Facade, Adapter, Command, Mediator (all six across
// both scenarios).
// -----------------------------------------------------------------------
void runScenarioTwo() {
    std::cout << "\n===== Scenario 2: Gas leak, Engineering Block =====\n";

    Incident incident("INC-1002", "Engineering Block", "Gas leak reported near lab 4");

    SecurityTeam security("Bravo Patrol", nullptr, std::unique_ptr<DispatchStrategy>(new PriorityEscortStrategy()));
    MedicalTeam medical("Medic Team 1", nullptr);
    FacilitiesStaff facilities("Facilities Crew B", nullptr);

    CampusGuardCoordinator coordinator(&security, &medical, &facilities);
    incident.attach(&coordinator);
    security.setMediator(&coordinator);
    medical.setMediator(&coordinator);
    facilities.setMediator(&coordinator);

    LegacyAlarmSystem legacyAlarm;
    LegacyAlertAdapter alertAdapter(&legacyAlarm);

    CampusGuardFacade facade(&security, &facilities, &alertAdapter);
    facade.declareEmergency(incident);

    // Subsystem operations stay independently usable outside the facade too:
    facilities.unlockArea(incident.getLocation());

    // Invalid-operation case, handled rather than ignored:
    OperatorConsole console;
    console.cancelLast(); // nothing has been issued on this console yet
}

int main() {
    runScenarioOne();
    runScenarioTwo();
    return 0;
}
