#include "Money.h"
#include <iostream>

using namespace std;

int main() {
    Money m1, m2;

    cout << "First amount: ";
    m1.Read();

    cout << "Second amount: ";
    m2.Read();

    Money sum = m1.Add(m2);
    Money diff = m1.Subtract(m2);
    Money mult = m1.Multiply(2.5);

    cout << "Addition: ";
    sum.Display();

    cout << "Subtraction: ";
    diff.Display();

    cout << "Multiplication by 2.5: ";
    mult.Display();

    return 0;
}