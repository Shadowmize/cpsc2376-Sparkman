#include "GradeBook.h"
#include <iostream>

void Book::add(std::shared_ptr<Watcher> w) {
    watchers.push_back(w);
}

void Book::change(float newGrade) {
    g = newGrade;
    std::cout << "Grade is now " << g << "\n";
    for (auto w : watchers) {
        w->check(g);
    }
}