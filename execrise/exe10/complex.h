#pragma once
class complex{
public:
    complex(){real = imagine = 0;};
    complex(double a, double b){
        real = a;
        b = imagine;
    };
    // double get_real();
    // double get_imagine();
    void print_info();
    friend complex operator +(const complex &a, const complex &b);
    friend complex operator -(const complex &a, const complex &b);
    friend complex operator *(const complex &a, const complex &b);
    friend complex operator /(const complex &a, const complex &b);
private:
    double real;
    double imagine;
};