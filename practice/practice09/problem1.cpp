//Used chatgpt to assist
#include <iostream>
#include <string>
#include <algorithm> 

int main() {
    float redPotion = 0.0f;
    float bluePotion = 0.0f;
    float* selectedPotion = nullptr;

    std::string input;
    float amount = 0.0f;

    while (true) {
        std::cout << "Add to which potion? (Red / Blue / Done): ";
        std::cin >> input;

        
        std::transform(input.begin(), input.end(), input.begin(), ::tolower);

        if (input == "done") {
            break;
        }

        if (input == "red") {
            selectedPotion = &redPotion;
        }
        else if (input == "blue") {
            selectedPotion = &bluePotion;
        }
        else {
            std::cout << "Try again.\n";
            continue;
        }

        std::cout << "Enter amount to add (mL): ";
        std::cin >> amount;

        if (selectedPotion) {
            *selectedPotion += amount;
        }

        std::cout << "Current potion amounts:\n";
        std::cout << "  Red: " << redPotion << " mL\n";
        std::cout << "  Blue: " << bluePotion << " mL\n\n";
    }

    return 0;
}
