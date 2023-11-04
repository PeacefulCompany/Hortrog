#pragma once

#include <string>
#include <vector>

namespace util {
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
} // namespace util
