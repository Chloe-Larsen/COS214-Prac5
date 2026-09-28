#include "LegacyAlarmSystem.h"
#include <iostream>

void LegacyAlarmSystem::triggerLegacyAlarm(int zoneCode, int severityLevel) {
    std::cout << "[LegacyAlarmSystem] ALARM zone=" << zoneCode
               << " severity=" << severityLevel << " (legacy hardware activated)\n";
}
