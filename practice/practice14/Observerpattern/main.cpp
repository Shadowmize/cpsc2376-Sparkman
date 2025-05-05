#include "GradeBook.h"
#include "GradeObservers.h"
#include <memory>
#include <iostream>

int main() {
    auto book = std::make_unique<Book>();
    book->add(std::make_shared<Average>());
    book->add(std::make_shared<Alert>());

    float input;
    while (true) {
        std::cout << "\nNew grade (-1 to quit): ";
        std::cin >> input;
        if (input == -1) break;
        book->change(input);
    }

    return 0;
}
