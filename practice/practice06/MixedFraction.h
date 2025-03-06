
#ifndef MIXEDFRACTION_H
#define MIXEDFRACTION_H

#include "Fraction.h"

class MixedFraction : public Fraction {
private:
    int wholePart;

public:
    MixedFraction(int whole = 0, int num = 0, int denom = 1);  // Constructor declaration with default arguments
    void setWholePart(int whole);
    int getWholePart() const;
    void display() const;

    friend std::ostream& operator<<(std::ostream& out, const MixedFraction& mf);
};

#endif
