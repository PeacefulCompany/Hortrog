#pragma once

#include <functional>

class Command {
public:
    using Callback = std::function<void()>;

    Command(Callback&& cb) : callback_(cb) {}

    void execute() { callback_(); }

private:
    Callback callback_;
};