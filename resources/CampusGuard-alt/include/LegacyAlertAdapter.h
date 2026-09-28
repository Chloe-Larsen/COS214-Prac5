#pragma once
#include "AlertSystem.h"

class LegacyAlarmSystem;

// Adapter: translates CampusGuard's sendAlert(message) calls into the
// legacy system's triggerLegacyAlarm(zoneCode, severityLevel) calls.
class LegacyAlertAdapter : public AlertSystem {
public:
    explicit LegacyAlertAdapter(LegacyAlarmSystem* legacySystem);

    void sendAlert(const std::string& message) override;

private:
    int mapMessageToZoneCode(const std::string& message) const;
    int mapMessageToSeverity(const std::string& message) const;

    LegacyAlarmSystem* legacySystem; // non-owning: legacy hardware interface outlives the adapter
};
