#include <fract_class.h>
#include <iostream>

using namespace std;

int main()
{
    Fraction fract1;
    init_fract(fract1);

    Fraction fract2;
    init_fract(fract2);

    Fraction fract3;

    void (*operations[4])(Fraction&, Fraction&, Fraction&) = {
        addition,
        subtraction,
        multiply,
        division
    };

    char operation = '\0';
    cout << "Choose operation( +, -, *, / ): ";
    cin >> operation;
    if (operation == '+')
        operations[0](fract1, fract2, fract3);
    else if (operation == '-')
        operations[1](fract1, fract2, fract3);
    else if (operation == '*')
        operations[2](fract1, fract2, fract3);
    else if (operation == '/')
        operations[3](fract1, fract2, fract3);
    else {
        cout << "incorrect choise";
        exit(0);
    }

    addition(fract1, fract2, fract3);
    fract_reduction(fract3);

    output_fract(fract1, fract2, fract3, '+');

    system("pause");
    return 0;
}
