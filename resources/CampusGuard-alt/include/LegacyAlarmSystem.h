#pragma once

// Adaptee: an existing campus alarm system with an incompatible interface.
// It works in numeric zone codes and severity levels, not free-text messages,
// and it is not something CampusGuard is allowed to modify.
class LegacyAlarmSystem {
public:
    void triggerLegacyAlarm(int zoneCode, int severityLevel);
};
