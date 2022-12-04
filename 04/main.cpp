#include "../aoc_utils.hpp"

std::vector<std::string> read_input(const char* filename) {
    std::ifstream raw_input(filename);
    std::vector<std::string> data;

    for (std::string i; std::getline(raw_input, i); ) {
        if (i.empty())
            continue;
        data.push_back(i);
    }

    return data;
}

struct ElfPair {
    long begin;
    long end;
    long size;
};

bool compare(const ElfPair& larger, const ElfPair& smaller, bool any) {
    if (larger.size < smaller.size) {
        return compare(smaller, larger, any);
    }
    if (any) {
        bool begin = larger.begin <= smaller.begin && larger.end >= smaller.begin;
        bool end = larger.begin <= smaller.end && larger.end >= smaller.end;
        return begin || end;
    }
    return larger.begin <= smaller.begin && larger.end >= smaller.end;
}

bool is_contained(const std::string& input, bool any = false) {
    std::regex find("(\\d+).(\\d+).(\\d+).(\\d+)");
    std::smatch match;

    bool found = std::regex_search(input, match, find);
    if (!found)
        return false;
    
    ElfPair first = {
        std::stol(match[1].str()),
        std::stol(match[2].str()),
        std::stol(match[2].str()) - std::stol(match[1].str())
    };
    ElfPair second = {
        std::stol(match[3].str()),
        std::stol(match[4].str()),
        std::stol(match[4].str()) - std::stol(match[3].str())
    };

    return compare(first, second, any);
}

int main() {
    auto test = read_input("test.txt");
    auto input = read_input("input.txt");

    std::cout << "Part 1\n------\n";

    long count = 0;
    for(auto& i : test) {
        if (is_contained(i))
            count += 1;
    }
    std::cout << "Test : " << count << "\n";

    count = 0;
    for(auto& i : input) {
        if (is_contained(i))
            count += 1;
    }
    std::cout << "Input: " << count << "\n";

    std::cout << "\nPart 2\n------\n";
    count = 0;
    for(auto& i : test) {
        if (is_contained(i, true))
            count += 1;
    }
    std::cout << "Test : " << count << "\n";

    count = 0;
    for(auto& i : input) {
        if (is_contained(i, true))
            count += 1;
    }
    std::cout << "Input: " << count << "\n";
}