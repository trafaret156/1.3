#include "Money.h"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

const int Money::hryvniasValues[9] = { 500,200,100,50,20,10,5,2,1 };
const int Money::penniesValues[6] = { 50,25,10,5,2,1 };

Money::Money() {
    for (int i = 0; i < 9; i++)
        hryvnias[i] = 0;
    for (int i = 0; i < 6; i++)
        pennies[i] = 0;
}

bool Money::Init(int h[9], int p[6]) {
    for (int i = 0; i < 9; i++) {
        if (h[i] < 0) return false;
        hryvnias[i] = h[i];
    }

    for (int i = 0; i < 6; i++) {
        if (p[i] < 0) return false;
        pennies[i] = p[i];
    }

    return true;
}

void Money::Read() {
    int h[9], p[6];

    cout << "Enter number of 500,200,100,50,20,10,5,2,1 UAH notes: ";
    for (int i = 0; i < 9; i++)
        cin >> h[i];

    cout << "Enter number of 50,25,10,5,2,1 kopeck coins: ";
    for (int i = 0; i < 6; i++)
        cin >> p[i];

    Init(h, p);
}

long long Money::CalculateSum() const {
    long long sum = 0;

    for (int i = 0; i < 9; i++)
        sum += hryvnias[i] * hryvniasValues[i] * 100;

    for (int i = 0; i < 6; i++)
        sum += pennies[i] * penniesValues[i];

    return sum;
}

void Money::FromSumPennies(long long sum) {
    if (sum < 0) sum = 0;

    for (int i = 0; i < 9; i++) {
        long long value = hryvniasValues[i] * 100;
        hryvnias[i] = sum / value;
        sum %= value;
    }

    for (int i = 0; i < 6; i++) {
        long long value = penniesValues[i];
        pennies[i] = sum / value;
        sum %= value;
    }
}

string Money::ToString() const {
    long long sum = CalculateSum();
    long long hryvniasPart = sum / 100;
    long long penniesPart = sum % 100;

    stringstream ss;
    ss << hryvniasPart << ",";

    if (penniesPart < 10)
        ss << "0";

    ss << penniesPart;

    return ss.str();
}

void Money::Display() const {
    cout << ToString() << endl;
}

Money Money::Add(const Money& other) const {
    Money result;
    result.FromSumPennies(this->CalculateSum() + other.CalculateSum());
    return result;
}

Money Money::Subtract(const Money& other) const {
    Money result;
    long long sum = this->CalculateSum() - other.CalculateSum();
    if (sum < 0) sum = 0;
    result.FromSumPennies(sum);
    return result;
}

Money Money::Multiply(double factor) const {
    Money result;
    long long sum = static_cast<long long>(
        round(this->CalculateSum() * factor)
        );
    result.FromSumPennies(sum);
    return result;
}