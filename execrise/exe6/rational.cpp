#include "rational.h"
#include <cassert>
#include <cmath>

rational_numbers::rational_numbers(int a, int b){
    assert(b != 0);
    numerator = a;
    denominator = b;
    this->normalize();
}

void rational_numbers::normalize(){
    // 处理两种情况 1. 分子分母同时为负 2. 分子为正，分母为负
    if((numerator < 0 && denominator < 0) || (numerator > 0 && denominator < 0)){
        numerator = -numerator;
        denominator = -denominator;
    }
    // 处理后的分母为正整数
    int i = std::abs(denominator);
    for(; i > 1; i--){
        if(((int)std::abs(numerator) % i == 0) && ((int)std::abs(denominator) % i == 0)){
            numerator /= i;
            denominator /= i;
            i = std::abs(denominator);
        }
    }
}

std::ostream& operator<<(std::ostream& out, const rational_numbers& obj){
    if(obj.numerator != 0){
        if(obj.denominator == 1){
            out << obj.numerator;
        } else {
            out << obj.numerator << "/" << obj.denominator;
        }
    } else {
        out << "0";
    }
    return out;
}

std::istream& operator >>(std::istream& in, rational_numbers& obj){
    char i;
    in >> obj.numerator >> i >> obj.denominator;
    assert(obj.denominator != 0 && i == '/');
    obj.normalize();
    return in;
}

rational_numbers operator +(const rational_numbers& a, const rational_numbers& b){
    int n = a.numerator*b.denominator + a.denominator*b.numerator;
    int m = a.denominator * b.denominator;
    return rational_numbers(n, m);
}

rational_numbers operator -(const rational_numbers& a, const rational_numbers& b){
    int n = a.numerator*b.denominator - a.denominator*b.numerator;
    int m = a.denominator * b.denominator;
    return rational_numbers(n, m);    
}

rational_numbers operator *(const rational_numbers& a, const rational_numbers& b){
    int n = a.numerator * b.numerator;
    int m = a.denominator * b.denominator;
    return rational_numbers(n, m);
}

rational_numbers operator /(const rational_numbers& a, const rational_numbers& b){
    int n = a.numerator * b.denominator;
    int m = a.denominator * b.numerator;
    return rational_numbers(n, m);
}

bool operator ==(const rational_numbers& a, const rational_numbers& b){
    // 因为都是化简过的分数，直接比较
    return ((a.numerator == b.numerator) && (a.denominator == b.denominator));
}
bool operator >(const rational_numbers& a, const rational_numbers& b){
    rational_numbers c = a - b;
    if(c.numerator <= 0){
        return false;
    } else {
        return true;
    }
}

bool operator <(const rational_numbers& a, const rational_numbers& b){
    if(a == b){
        return false;
    } else {
        return !(a > b);
    }
}