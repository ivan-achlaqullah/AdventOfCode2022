#include "../aoc_utils.hpp"

std::vector<long> read_input(const char* filename) {
    std::ifstream raw_input(filename);
    std::vector<long> data = {0};

    for (std::string i; std::getline(raw_input, i); ) {
        if (i.empty()) {
            data.push_back(0);
            continue;
        }
        data[data.size() -1] += std::stol(i);
    }

    if (data[data.size() - 1] == 0) {
        data.pop_back();
    }

    std::sort(data.begin(), data.end());

    return data;
}

long part_1(const std::vector<long>& data) {
    return data[data.size() - 1];
}

long part_2(const std::vector<long>& data) {
    long top3 = 0;
    for (size_t i = 0; i < 3; i++){
        top3 += data[data.size() - 1 - i];
    }
    return top3;
}

int main() {
    auto test = read_input("test.txt");
    auto input = read_input("input.txt");

    std::cout << "Test\n";
    std::cout << "1st part: " << part_1(test) << "\n";
    std::cout << "2nd part: " << part_2(test) << "\n";

    std::cout << "\nInput\n";
    std::cout << "1st part: " << part_1(input) << "\n";
    std::cout << "2nd part: " << part_2(input) << "\n";
}