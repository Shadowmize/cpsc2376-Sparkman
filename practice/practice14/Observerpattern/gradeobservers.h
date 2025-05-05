#pragma once
#include "GradeObserver.h"
#include <iostream>

class Average : public Watcher {
    float total = 0;
    int num = 0;
public:
    void check(float grade) override;
};

class Alert : public Watcher {
public:
    void check(float grade) override;
};