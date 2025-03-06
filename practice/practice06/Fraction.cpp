#include "Fraction.h"
#include <iostream>
#include <stdexcept>
#include <cmath>  

Fraction::Fraction(int n, int d) : num(n), denom(d) {
    if (denom == 0) throw std::invalid_argument("Denominator cannot be zero");
    simplify();
}

void Fraction::setNumerator(int n) { num = n; }

void Fraction::setDenominator(int d) {
    if (d == 0) throw std::invalid_argument("Denominator cannot be zero");
    denom = d;
    simplify();
}

int Fraction::getNumerator() const { return num; }

int Fraction::getDenominator() const { return denom; }

void Fraction::simplify() {
    int gcd = 1;
    for (int i = 2; i <= abs(num) && i <= abs(denom); i++)
        if (num % i == 0 && denom % i == 0) gcd = i;

    num /= gcd;
    denom /= gcd;

    if (denom < 0) {  
        num = -num;
        denom = -denom;
    }
}

Fraction Fraction::operator+(const Fraction& f) {
    return Fraction(num * f.denom + f.num * denom, denom * f.denom);
}

Fraction Fraction::operator-(const Fraction& f) {
    return Fraction(num * f.denom - f.num * denom, denom * f.denom);
}

Fraction Fraction::operator*(const Fraction& f) {
    return Fraction(num * f.num, denom * f.denom);
}

Fraction Fraction::operator/(const Fraction& f) {
    if (f.num == 0) throw std::invalid_argument("Division by zero is not allowed");
    return Fraction(num * f.denom, denom * f.num);
}

std::ostream& operator<<(std::ostream& out, const Fraction& f) {
    out << f.num << "/" << f.denom;
    return out;
}
