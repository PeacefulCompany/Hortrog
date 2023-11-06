#pragma once

#include "core/Command.h"
#include <functional>
#include <optional>
#include <string>
#include <utility>

class CommandMenu {
public:
    /**
     * @brief Adds a command to the menu
     *
     * @param label The label to display for the command
     * @param callback The callback function to execute if the command is
     * selected
     */
    void addCommand(const std::string& label, Command::Callback&& callback);

    /**
     * @brief Takes the user input and executes the corresponding command
     *
     * @return int 0 if successful, or -1 if the exit code was entered
     */
    int execute();

    inline void setPrompt(const std::string& prompt) { prompt_ = prompt; }
    inline void setError(const std::string& error) { error_ = error; }
    inline void setExitCode(int code) { exitCode_ = code; }

private:
    bool isValid(int opt) const;
    std::optional<int> exitCode_;
    std::string prompt_ = "Enter an option: ";
    std::string error_ = "Invalid option. Try again.";
    std::vector<std::pair<std::string, Command>> commands_;
};