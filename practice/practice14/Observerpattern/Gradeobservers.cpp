#include "GradeObservers.h"

void Average::check(float grade) {
    total += grade;
    num++;
    std::cout << "Avg: " << (total / num) << "\n";
}

void Alert::check(float grade) {
    if (grade < 60) {
        std::cout << "Email sent to student@example.com\n";
    }
}