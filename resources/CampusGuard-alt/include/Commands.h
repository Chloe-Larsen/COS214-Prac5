#pragma once
#include "Command.h"
#include <string>

class SecurityTeam;
class FacilitiesStaff;
class AlertSystem;
class Incident;

// ConcreteCommand: dispatch security to the incident location.
class DispatchUnitCommand : public Command {
public:
    DispatchUnitCommand(SecurityTeam* receiver, Incident* incident);
    void execute() override;
    void undo() override;
private:
    SecurityTeam* receiver; // non-owning
    Incident* incident;     // non-owning
};

// ConcreteCommand: lock down a building/area.
class LockAreaCommand : public Command {
public:
    LockAreaCommand(FacilitiesStaff* receiver, std::string location);
    void execute() override;
    void undo() override;
private:
    FacilitiesStaff* receiver; // non-owning
    std::string location;
};

// ConcreteCommand: raise a campus-wide alert.
class IssueAlertCommand : public Command {
public:
    IssueAlertCommand(AlertSystem* receiver, std::string message);
    void execute() override;
    void undo() override;
private:
    AlertSystem* receiver; // non-owning
    std::string message;
};
