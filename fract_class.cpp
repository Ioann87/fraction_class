#include <cmath>
#include <fract_class.h>
#include <iomanip>
#include <iostream>
using namespace std;

void Fraction::setter(int num, int denom)
{
    numerator = num;
    denominator = denom;
    return;
}

int Fraction::get_num()
{
    return numerator;
}

int Fraction::get_denom()
{
    return denominator;
}

void init_fract(Fraction& object)
{
    int num = 0;
    int denom = 0;
    static int count = 1;

    cout << "Enter a fraction " << count << " : " << endl;
    cin >> num;
    cout << "---" << endl;
    cin >> denom;
    object.setter(num, denom);
    count++;
    return;
}

void addition(Fraction& obj1, Fraction& obj2, Fraction& obj3)
{
    int numer = 0;
    int denom = 0;

    if (obj1.get_denom() == obj2.get_denom()) {
        numer = obj1.get_num() + obj2.get_num();
        denom = obj2.get_denom();
        obj3.setter(numer, denom);
    } else {
        int result = 0;
        numer = obj1.get_num() * obj2.get_denom();
        denom = obj1.get_denom() * obj2.get_denom();
        result += numer;
        numer = obj2.get_num() * obj1.get_denom();
        result += numer;
        obj3.setter(result, denom);
    }
    return;
}

void subtraction(Fraction& obj1, Fraction& obj2, Fraction& obj3)
{
    int numer = 0;
    int denom = 0;

    if (obj1.get_denom() == obj2.get_denom()) {
        numer = obj1.get_num() + obj2.get_num();
        denom = obj2.get_denom();
        obj3.setter(numer, denom);
    } else {
        int result = 0;
        numer = obj1.get_num() * obj2.get_denom();
        denom = obj1.get_denom() * obj2.get_denom();
        result += numer;
        numer = obj1.get_num() * obj2.get_denom();
        result -= numer;
        obj3.setter(result, denom);
    }
    return;
}

void multiply(Fraction& obj1, Fraction& obj2, Fraction& obj3)
{
    obj3.setter(obj1.get_num() * obj2.get_num(),
        obj1.get_denom() * obj2.get_denom());
    return;
}

void division(Fraction& obj1, Fraction& obj2, Fraction& obj3)
{
    obj3.setter(obj1.get_num() * obj2.get_denom(),
        obj1.get_denom() * obj2.get_num());
    return;
}

void fract_reduction(Fraction& object)
{
    int num = object.get_num();
    int denom = object.get_denom();
    int divisor = gcd(num, denom);
    if (divisor != 0) {
        num /= divisor;
        denom /= divisor;
        object.setter(num, denom);
    }
    return;
}

int gcd(int& num, int& denom)
{
    int a = 0;
    int b = 0;
    int temp = 0;
    if (num > denom) {
        a = abs(num);
        b = abs(denom);
    } else if (num < denom) {
        a = abs(denom);
        b = abs(num);
    }
    while (a != b) {
        if (a > b) {
            temp = a;
            a = b;
            b = temp;
        }
        b = b - a;
    }
    return a;
}

void output_fract(Fraction& obj1, Fraction& obj2, Fraction& obj3, char operation)
{
    if (obj3.get_num() < obj3.get_denom()) {
        cout << setw(2) << obj1.get_num()
             << setw(7) << obj2.get_num()
             << setw(10) << obj3.get_num() << endl;
        cout << "----" << setw(2) << operation
             << " ----" << setw(5) << " = "
             << "----" << endl;
        cout << setw(2) << obj1.get_denom()
             << setw(7) << obj2.get_denom()
             << setw(10) << obj3.get_denom() << endl;
    } else if (obj3.get_num() > obj3.get_denom()) {
        cout << setw(2) << obj1.get_num()
             << setw(7) << obj2.get_num()
             << setw(10) << obj3.get_num() % obj3.get_denom()
             << endl;
        cout << "----" << setw(2) << operation
             << " ----" << setw(5) << " = "
             << obj3.get_num() / obj3.get_denom()
             << "----" << endl;
        cout << setw(2) << obj1.get_denom()
             << setw(7) << obj2.get_denom()
             << setw(10) << obj3.get_denom() << endl;
    }
    return;
}
