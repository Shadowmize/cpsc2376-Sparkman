#pragma once

class Watcher {
public:
    virtual void check(float grade) = 0;
    virtual ~Watcher() {}
};
