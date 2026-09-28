#include "DispatchStrategy.h"

std::string NearestUnitStrategy::describeApproach(const std::string& location) const {
    return "nearest available patrol routed directly to " + location;
}

std::string PriorityEscortStrategy::describeApproach(const std::string& location) const {
    return "priority escort convoy dispatched to " + location + " with backup on standby";
}
