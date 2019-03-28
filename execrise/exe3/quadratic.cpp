#include "quadratic.h"
#include <cmath>

void quadratic::set_coefficients(double m, double n, double q){
    a = m;
    b = n;
    c = q;
}

double quadratic::get_a() const{
    return a;
}

double quadratic::get_b() const{
    return b;
}

double quadratic::get_c() const{
    return c;
}

double quadratic::evaluate_exp(double x){
    return a * pow(x, 2) + b * x + c;
}

quadratic operator +(const quadratic& q1, const quadratic& q2){
    quadratic q3;
    q3.set_coefficients(q1.get_a() + q2.get_a(), q1.get_b() + q2.get_b(), q1.get_c() + q2.get_c());
    return q3;
}

quadratic operator *(double r, const quadratic& q){
    quadratic q1;
    q1.set_coefficients(r * q.get_a(), r * q.get_b(), r * q.get_c());
    return q1;
}