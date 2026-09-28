#include "ResponseComponent.h"
#include "ResponseMediator.h"

void ResponseComponent::notifyMediator(const std::string& event) {
    mediator->notify(this, event);
}
