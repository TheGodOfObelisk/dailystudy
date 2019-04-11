#pragma once

#include <iostream>

class rational_numbers{
public:
    rational_numbers(){
        numerator = 0;
        denominator = 1;
    };
    rational_numbers(int a, int b);
    friend std::ostream& operator <<(std::ostream& out, const rational_numbers& obj);
    friend std::istream& operator >>(std::istream& in, rational_numbers& obj);
    friend rational_numbers operator +(const rational_numbers& a, const rational_numbers& b);
    friend rational_numbers operator -(const rational_numbers& a, const rational_numbers& b);
    friend rational_numbers operator *(const rational_numbers& a, const rational_numbers& b);
    friend rational_numbers operator /(const rational_numbers& a, const rational_numbers& b);
    friend bool operator ==(const rational_numbers& a, const rational_numbers& b);
    friend bool operator >(const rational_numbers& a, const rational_numbers& b);
    friend bool operator <(const rational_numbers& a, const rational_numbers& b);
private:
    void normalize();
    int numerator, denominator;
};

