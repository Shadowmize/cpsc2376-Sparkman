// used chat gpt to assist
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::vector<int> numbers;
    int num;

    std::cout << "Type some numbers (press 'q' when done): ";
    while (std::cin >> num) {
        numbers.push_back(num);
    }

    std::cin.clear();
    std::cin.ignore(10000, '\n');

    std::cout << "Numbers squared: ";
    std::for_each(numbers.begin(), numbers.end(), [](int n) {
        std::cout << (n * n) << " ";
        });
    std::cout << "\n";

    int sum_of_squares = std::accumulate(numbers.begin(), numbers.end(), 0, [](int sum, int n) {
        return sum + (n * n);
        });

    std::cout << "Total sum of squares: " << sum_of_squares << "\n";

    return 0;

    }