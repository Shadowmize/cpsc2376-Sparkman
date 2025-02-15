
#include <iostream>
#include <string>

int main() {
   int choice;
   std::string name, greetingPrefix;

   std::cout << "1. Default Greeting\n";
    std::cout << "2. Greet by Name\n";
    std::cout << "3. Custom Greeting\n";
    std::cout << "Choose an option: ";
    std::cin >> choice;

    if(choice == 1) {

        std::cout << "Hello, Guest!";
        
    
       }else if(choice == 2) {

        std::cout << "Enter Name: ";
        std::cin >> name;
        std::cout << "hello, " << name << "!\n";
    
       }
       else if (choice == 3) {
        std::cout << "Enter Greeting Prefix ";
        std::cin >> greetingPrefix;
        std::cout << "Enter Name ";
        std::cin >> name;
        std::cout << greetingPrefix << ", " << name << "!\n";
    
       }else {
        std::cout << "invalid option";
       }
      
    
        return 0;
    }

   