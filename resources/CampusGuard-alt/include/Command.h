#pragma once

// Command interface: every operator action is an object, so it can be
// queued, logged and (where meaningful) undone, instead of being an
// immediate direct method call from the UI layer.
class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
    virtual void undo() = 0;
};
