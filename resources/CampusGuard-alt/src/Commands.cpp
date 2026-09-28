#include "Commands.h"
#include "SecurityTeam.h"
#include "FacilitiesStaff.h"
#include "AlertSystem.h"
#include "Incident.h"
#include <iostream>

DispatchUnitCommand::DispatchUnitCommand(SecurityTeam* receiver_, Incident* incident_)
    : receiver(receiver_), incident(incident_) {}

void DispatchUnitCommand::execute() {
    receiver->dispatchTo(incident->getLocation());
    incident->setStatus(IncidentStatus::DISPATCHED);
}

void DispatchUnitCommand::undo() {
    std::cout << "[DispatchUnitCommand] undo: recalling " << receiver->getName() << "\n";
}

LockAreaCommand::LockAreaCommand(FacilitiesStaff* receiver_, std::string location_)
    : receiver(receiver_), location(std::move(location_)) {}

void LockAreaCommand::execute() {
    receiver->lockArea(location);
}

void LockAreaCommand::undo() {
    receiver->unlockArea(location);
}

IssueAlertCommand::IssueAlertCommand(AlertSystem* receiver_, std::string message_)
    : receiver(receiver_), message(std::move(message_)) {}

void IssueAlertCommand::execute() {
    receiver->sendAlert(message);
}

void IssueAlertCommand::undo() {
    std::cout << "[IssueAlertCommand] undo: cannot recall an alert already sent (\""
               << message << "\") -- logging cancellation notice instead\n";
}
