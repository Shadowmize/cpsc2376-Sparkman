//Used chatgpt to assist
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;
    int num;
    
    std::cout << "type some numbers (hit 'q' when you're done): ";
    while (std::cin >> num) {
        numbers.push_back(num);
    }
    
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    
    std::cout << "here's what you entered: ";
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    
    int even_sum = 0;
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        if (*it % 2 == 0) {
            even_sum += *it;
        }
    }
    
    std::cout << "Sum of the even numbers: " << even_sum << "\n";
    
    return 0;
}
