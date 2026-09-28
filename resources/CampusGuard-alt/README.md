# CampusGuard

## Build and run (Docker)

```
docker compose up --build
```

## Build and run (local)

```
make
./campusguard
```

## Patterns implemented
- Command: `Command`, `DispatchUnitCommand`, `LockAreaCommand`, `IssueAlertCommand`, invoked by `OperatorConsole`
- Mediator: `ResponseMediator` / `CampusGuardCoordinator` coordinating `SecurityTeam`, `MedicalTeam`, `FacilitiesStaff`
- Adapter: `LegacyAlertAdapter` adapts `LegacyAlarmSystem` to the `AlertSystem` interface
- Facade: `CampusGuardFacade::declareEmergency` coordinates security, facilities and alerts in one call
- Observer: `IncidentObserver` / `Incident` notifies `CampusGuardCoordinator` of status changes
- Strategy: `DispatchStrategy` (`NearestUnitStrategy`, `PriorityEscortStrategy`) used by `SecurityTeam`
