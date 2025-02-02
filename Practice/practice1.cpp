// Used chatgpt for the print multiples of a user defined value
// had some errors used chatgpt to help them but they 
//were all spelling mistakes and i made calculate sum a void  method instead of int
#include <iostream>
#include <vector>

void printVector(const std::vector<int>& vec) { 
    std::cout << "This is your vector: ";
    for (size_t i = 0; i < vec.size(); i++) { 
        std::cout << vec[i] << " ";            
    }
    std::cout << std::endl;             
}

void doubleVector(std::vector<int>& vec) {      
    for (size_t i = 0; i < vec.size(); i++) {   
        vec[i] = vec[i] * 2;                   
    }
    std::cout << "The numbers are doubled." << std::endl;
}

int calculateSum(const std::vector<int>& vec) { 
    int sum = 0;                                   
    for (size_t i = 0; i < vec.size(); i++) {      
        sum = sum + vec[i];                      
    }                               
    return sum; 
}

void printMultiples(const std::vector<int>& vec, int multiple) {            
    std::cout << "Numbers that are multiples of " << multiple << ": ";
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] % multiple == 0) {
            std::cout << vec[i] << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> numbers;
    int choice;

    do {
        std::cout << "\nMenu: \n";
        std::cout << "1. Add number\n";         
        std::cout << "2. Show numbers\n";
        std::cout << "3. Double numbers\n";
        std::cout << "4. Get sum\n";
        std::cout << "5. Find multiples\n";
        std::cout << "6. Quit\n";
        std::cin >> choice;

        switch (choice) {
            case 1: {      
                int value;
                std::cout << "Enter a number: ";
                std::cin >> value;
                numbers.push_back(value);      
                break;          
            }
            case 2:
                printVector(numbers); 
                break;
            case 3:
                doubleVector(numbers); 
                break;
            case 4:
                std::cout << "Total sum: " << calculateSum(numbers) << std::endl; 
                break;
            case 5: {
                int multiple;
                std::cout << "Enter a number to check what its multiples are: ";  
                std::cin >> multiple;
                printMultiples(numbers, multiple);
                break;
            }
            case 6:
                std::cout << "See ya!" << std::endl; 
                break;
            default: 
                std::cout << "Oops! Try again." << std::endl; 
        }
    } while (choice != 6); 

    return 0;
}
