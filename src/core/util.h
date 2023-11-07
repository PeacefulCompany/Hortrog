#pragma once

#include <string>
#include <vector>

namespace util {
namespace {
const std::string ESC = "\x1b";
}

const std::string CLEAR_SCREEN = ESC + "[2J";
const std::string HOME = ESC + "[H";

/**
 * @brief Removes any trailing whitespace from the start and end of a string
 *
 * @param str The string to trim
 * @return std::string A new string with trailing whitespace removed
 */
std::string trim(const std::string& str);

/**
 * @brief Formats a list of options for output
 *
 * @param opts The options to display
 * @return std::string The formatted result
 */
std::string options(const std::vector<std::string>& opts);

/**
 * @brief Takes an integer input from the user
 *
 * @param prompt The prompt to display
 * @return int
 */
int input(const std::string& prompt);

/**
 * @brief Displays an error and waits for user input
 *
 * @param error The error message to display
 */
void error(const std::string& error);

/**
 * @brief Inputs a string
 *
 * @param prompt The prompt to display
 * @return std::string
 */
std::string inputString(const std::string& prompt);
} // namespace util
