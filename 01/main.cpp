#include "../aoc_utils.hpp"

int main() {
    std::ifstream raw_test("test.txt");
    std::ifstream raw_input("input.txt");

    std::vector<long> data = {0};

    for (std::string i; std::getline(raw_input, i); ){
        if (i.empty()){
            data.push_back(0);
            continue;
        }
        data[data.size() -1] += std::stol(i);
    }

    if (data[data.size() - 1] == 0) {
        data.pop_back();
    }

    std::sort(data.begin(), data.end());

    std::cout << "First part: " << data[data.size() - 1] << "\n";

    long top3 = 0;
    for (size_t i = 0; i < 3; i++){
        top3 += data[data.size() - 1 - i];
    }

    std::cout << "Second part: " << top3 << "\n";
}