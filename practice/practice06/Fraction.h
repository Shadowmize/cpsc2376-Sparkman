#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <stdexcept> 

class Fraction {
protected:
    int num; 
    int denom;  

public:
    
    Fraction(int n = 0, int d = 1);  
    void setNumerator(int n);
    void setDenominator(int d); 
    int getNumerator() const;
    int getDenominator() const;

   
    void simplify();

    
    Fraction operator+(const Fraction& f);
    Fraction operator-(const Fraction& f);
    Fraction operator*(const Fraction& f);
    Fraction operator/(const Fraction& f);  

   
    friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
};

#endif
