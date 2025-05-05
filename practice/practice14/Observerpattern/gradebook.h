#pragma once
#include "GradeObserver.h"
#include <vector>
#include <memory>

class Book {
    float g = 100;
    std::vector<std::shared_ptr<Watcher>> watchers;
public:
    void add(std::shared_ptr<Watcher> w);
    void change(float newGrade);
};