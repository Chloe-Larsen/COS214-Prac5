# Concise Design and Ownership Rationale

CampusGuard is an emergency/incident response system implementing six GoF design patterns:

- Composite (AreaComponent, Area, AreaGroup) - models the campus as a hierarchy of lockable areas.
- State (IncidentState and its five concrete states) - governs the lifecycle of an incident from reported to closed.
- Command (Command, LockAreaCommand, CancelActionCommand, DispatchUnitCommand, IssueAlertCommand) - encapsulates operator actions as undoable objects.
- Mediator (ResponseMediator, IncidentCoordinator, ResponseUnit subclasses) - decouples response units from each other via a central coordinator.
- Facade (EmergencyResponseFacade) - provides a single simplified entry point for lockdown/alert operations.
- Adapter (CityBroadcastAdapter, LegacyCityBroadcastSystem) - bridges the modern alert interface to a legacy broadcast system.

Composite and State were the two additional patterns selected by the team (beyond the four required - Command, Mediator, Adapter, Facade), chosen because area locking naturally forms a part-whole hierarchy, and incident handling naturally forms a lifecycle with distinct behaviour per stage.

Ownership and process:
The team split work by project phase rather than by individual class, matching how the six patterns interact as one coherent design rather than independent parts:
- Zander owned Task 1 - the complete system design, including the class diagram and formal identification/justification of all six GoF patterns.
- Chloe owned Task 2 and 3 - translating that design into working C++ implementation for all six patterns.
- Lebo owned engineering-quality documentation and one of the two Task 4 sequence diagrams, verifying the design matched the implementation when writing up the GitHub history and rationale.
