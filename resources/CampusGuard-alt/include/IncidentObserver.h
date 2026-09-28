#pragma once

class Incident; // forward declaration

// Observer pattern: participants get notified when an Incident's status changes,
// without the Incident needing to know who they are.
class IncidentObserver {
public:
    virtual ~IncidentObserver() = default;
    virtual void onIncidentStatusChanged(const Incident& incident) = 0;
};
