#include "CommandMenu.h"
#include "core/Command.h"
#include "core/util.h"

#include <iostream>

void CommandMenu::addCommand(
    const std::string& label, Command::Callback&& callback) {
    commands_.emplace_back(label, Command(std::move(callback)));
}
int CommandMenu::execute() {
    for (int i = 0; i < commands_.size(); i++) {
        std::cout << (i + 1) << ") " << commands_[i].first << std::endl;
    }
    int opt = util::input(prompt_);

    while (!isValid(opt)) {
        std::cout << error_ << std::endl;
        opt = util::input(prompt_);
    }
    if (opt == exitCode_) return -1;
    commands_[opt - 1].second.execute();

    return 0;
}

bool CommandMenu::isValid(int opt) const {
    if (exitCode_ && opt == exitCode_) return true;
    if (opt < 1) return false;
    if (opt > commands_.size()) return false;
    return true;
}
