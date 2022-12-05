#include "../aoc_utils.hpp"

std::vector<std::string> read_input(const char* filename) {
    std::ifstream raw_input(filename);
    std::vector<std::string> data;

    for (std::string i; std::getline(raw_input, i); ) {
        data.push_back(i);
    }

    return data;
}

int count_stacks(const std::vector<std::string>& input) {
    int max_stack = 0;
    for (auto& i : input) {
        if (i.substr(0, 3) != " 1 ") {
            continue;
        }
        auto find = i.find("9");
        max_stack = 9;
        if(find == std::string::npos){
            max_stack = 3;
        }
        break;
    }
    return max_stack;
}

std::vector<std::string> parse_cargo(const std::vector<std::string>& input) {
    std::vector<std::string> result;
    int max_stack = count_stacks(input);
    for (int i = 0; i < max_stack; i++) {
        result.push_back("");
    }

    for (auto& line : input) {
        if(line.substr(0, 3) == " 1 "){
            break;
        }
        for (int i = 0; i < max_stack; i++) {
            result[i] += line[1 + i * 4];
        }
    }

    for (size_t i = 0; i < result.size(); i++) {
        std::reverse(result[i].begin(), result[i].end());
    }

    return result;
}

int main() {
    auto test = read_input("test.txt");
    auto test_res = parse_cargo(test);

    for (auto& i : test_res) {
        std::cout << i << "\n";
    }
}