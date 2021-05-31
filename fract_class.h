#ifndef FRACT_CLASS_H
#define FRACT_CLASS_H

class Fraction {
private:
    int numerator;
    int denominator;

public:
    void setter(int num, int denom);
    int get_num();
    int get_denom();
};

void init_fract(Fraction& object);

void addition(Fraction& obj1, Fraction& obj2, Fraction& obj3);

void subtraction(Fraction& obj1, Fraction& obj2, Fraction& obj3);

void multiply(Fraction& obj1, Fraction& obj2, Fraction& obj3);

void division(Fraction& obj1, Fraction& obj2, Fraction& obj3);

void fract_reduction(Fraction& object);

int gcd(int& num, int& denom);

void output_fract(Fraction& obj1, Fraction& obj2, Fraction& obj3, char operation);

#endif // FRACT_CLASS_H
