#include "MixedFraction.h"
#include <iostream>

MixedFraction::MixedFraction(int whole, int num, int denom) : Fraction(num, denom), wholePart(whole) {}

void MixedFraction::setWholePart(int whole) {
    wholePart = whole;
}

int MixedFraction::getWholePart() const {
    return wholePart;
}

void MixedFraction::display() const {
    std::cout << wholePart << " " << getNumerator() << "/" << getDenominator() << std::endl;
}


std::ostream& operator<<(std::ostream& out, const MixedFraction& mf) {
    out << mf.getWholePart() << " " << mf.getNumerator() << "/" << mf.getDenominator();
    return out;
}
