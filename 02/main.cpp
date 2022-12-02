#include "../aoc_utils.hpp"

std::unordered_map<std::string, long> read_input(const char* filename) {
    std::ifstream raw_input(filename);
    std::unordered_map<std::string, long> data;

    for (std::string i; std::getline(raw_input, i); ) {
        if (i.empty())
            continue;
        //if (data.contains(i)) {
        if (data.count(i) == 1) {
            data[i] += 1;
        } else {
            data[i] = 1;
        }
    }

    return data;
}

long convert(char input) {
    std::unordered_map<char, long> table = {
        {'A', 1},
        {'B', 2},
        {'C', 3},
        {'X', 1},
        {'Y', 2},
        {'Z', 3},
    };
    return table[input];
}

long part1(const std::string& input) {
    long you = convert(input[2]);
    long opp = convert(input[0]);

    if (you == opp)
        return you + 3;
    if (you == 1 && opp == 3)
        return you + 6;
    if (you == opp + 1)
        return you + 6;
    
    return you;
}

long part2(const std::string& input) {
    long opp = convert(input[0]) - 1;
    long win_hand = (opp + 1) % 3;
    long lose_hand = (opp + 2) % 3;
    opp += 1;
    win_hand += 1;
    lose_hand += 1;

    char order = input[2];
    if (order == 'X')
        return lose_hand;
    if (order == 'Y')
        return opp + 3;
    return win_hand + 6;
}

int main() {
    auto test = read_input("test.txt");
    auto input = read_input("input.txt");

    long result = 0;
    for (auto& rps_round : input) {
        result += part1(rps_round.first) * rps_round.second;
    }
    std::cout << "Part 1: " << result << "\n";

    result = 0;
    for (auto& rps_round : input){
        result += part2(rps_round.first) * rps_round.second;
    }
    std::cout << "Part 2: " << result << "\n";
}