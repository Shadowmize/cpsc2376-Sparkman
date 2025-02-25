// used chatgpt to assist
#include <iostream>
#include <vector>
#include <algorithm> 

int main() {
    std::vector<int> numbers = { 5, 36, 55, 42, 87, 14, 92 };

    auto maxIt = std::max_element(numbers.begin(), numbers.end());


    auto minIt = std::min_element(numbers.begin(), numbers.end());

    if (maxIt != numbers.end()) {
        std::cout << "Largest element: " << *maxIt << std::endl;
    }

    if (minIt != numbers.end()) {
        std::cout << "Smallest element: " << *minIt << std::endl;
    }

    return 0;
}
