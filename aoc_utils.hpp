#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <regex>
#include <algorithm>

int test_func_regex() {
    std::regex find("digit (\\d+)");
    std::string text("digit 2022");

    std::smatch match;
    if (std::regex_search(text, match, find)) {
        auto res = match[1].str();
        return std::stoi(res);
    }
    return -1;
}