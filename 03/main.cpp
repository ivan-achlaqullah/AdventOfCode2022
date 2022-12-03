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

int convert_to_priority(char input) {
    char min_lower = 'a';
    char max_lower = 'z';
    char min_upper = 'A';
    
    if (input >= min_lower && input <= max_lower) {
        return input - min_lower + 1;
    }

    return input - min_upper + 27;
}

int part_one(const std::string& input) {
    auto half = input.size() / 2;
    auto first_half = input.substr(0, half);
    auto second_half = input.substr(half);

    for (auto i : first_half) {
        auto found = second_half.find(i);
        if (found == std::string::npos) {
            continue;
        }
        return convert_to_priority(i);
    }

    return 0;
}

long part_two(const std::vector<std::string>& input) {
    long result = 0;
    for(size_t i = 0; i < input.size(); i += 3) {
        for (auto j : input[i]) {
            auto found = input[i + 1].find(j);
            if (found == std::string::npos)
                continue;
            found = input[i + 2].find(j);
            if (found == std::string::npos)
                continue;
            result += convert_to_priority(j);
            break;
        }
    }
    return result;
}

int main() {
    auto test = read_input("test.txt");
    auto input = read_input("input.txt");
    
    std::cout << "Part 1\n";

    long total = 0;
    for (auto& i : test) {
        total += part_one(i);
    }
    std::cout << "Test : " << total << "\n";

    total = 0;
    for (auto& i : input) {
        total += part_one(i);
    }
    std::cout << "Input: " << total << "\n";

    std::cout << "\nPart 2\n";
    std::cout << "Test : " << part_two(test) << "\n";
    std::cout << "Input: " << part_two(input) << "\n";
}