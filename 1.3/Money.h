#pragma once
#include <string>

class Money {
private:
    int hryvnias[9];  
    int pennies[6];    

    static const int hryvniasValues[9];
    static const int penniesValues[6];

    long long CalculateSum() const;
    void FromSumPennies(long long sum);

public:
    Money();

    bool Init(int h[9], int p[6]);
    void Read();
    void Display() const;
    std::string ToString() const;

    Money Add(const Money& other) const;
    Money Subtract(const Money& other) const;
    Money Multiply(double factor) const;
};