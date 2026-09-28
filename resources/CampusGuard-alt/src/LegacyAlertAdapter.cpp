#include "LegacyAlertAdapter.h"
#include "LegacyAlarmSystem.h"
#include <iostream>

LegacyAlertAdapter::LegacyAlertAdapter(LegacyAlarmSystem* legacySystem_)
    : legacySystem(legacySystem_) {}

void LegacyAlertAdapter::sendAlert(const std::string& message) {
    std::cout << "[LegacyAlertAdapter] translating \"" << message << "\" for legacy hardware\n";
    legacySystem->triggerLegacyAlarm(mapMessageToZoneCode(message), mapMessageToSeverity(message));
}

int LegacyAlertAdapter::mapMessageToZoneCode(const std::string& /*message*/) const {
    // Simplified mapping for demo purposes.
    return 7;
}

int LegacyAlertAdapter::mapMessageToSeverity(const std::string& message) const {
    return message.find("evacuate") != std::string::npos ? 3 : 1;
}
