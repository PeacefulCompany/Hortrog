#include "util.h"
#include <iostream>
#include <sstream>
#include <string>

namespace util {
std::string trim(const std::string& str) {
    int start = 0;
    int end = str.length() - 1;

    for (start = 0; start < str.length(); start++) {
        if (!isspace(str[start])) break;
    }

    for (end = str.length() - 1; end >= 0; end--) {
        if (!isspace(str[start])) break;
    }

    return str.substr(start, end - start + 1);
}

std::string options(const std::vector<std::string>& opts) {
    std::stringstream stream;
    for (int i = 0; i < opts.size(); i++) {
        stream << (i + 1) << ") " << opts[i] << "\n";
    }
    std::string result = stream.str();
    return result.substr(0, result.size() - 1);
}
int input(const std::string& prompt) {
    int value;
    std::cout << prompt;
    std::cin >> value;
    while (std::cin.fail()) {
        std::cin.ignore(255, '\n');
        std::cin.clear();

        std::cout << "Invalid input. Try again." << std::endl;

        std::cout << prompt;
        std::cin >> value;
    }
    std::cin.ignore(255, '\n');
    return value;
}

void error(const std::string& error) {
    std::cout << error << std::endl;
    std::cin.get();
}

std::string inputString(const std::string& prompt) {
    std::string line;
    std::cout << prompt;
    std::getline(std::cin, line);
    return line;
}
} // namespace util
