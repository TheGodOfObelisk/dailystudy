#include "quadratic.h"
#include <cmath>
#include <assert.h>
#include <iostream>

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

int quadratic::root_num(){
    if(!(a || b || c))
        return 3;// stands for infinity
    if(a == 0 && b == 0 && c!=0)
        return 0;
    if(a == 0 && b !=0)
        return 1;
    if(a != 0 && pow(b, 2) < 4*a*c)
        return 0;
    if(a != 0 && pow(b, 2) == 4*a*c)
        return 1;
    if(a != 0 && pow(b, 2) > 4*a*c)
        return 2;
    return -1;
}

double quadratic::root1(){
    assert(root_num() != 0);
    if(root_num() == 1 && a == 0)
        return -c/b;
    if(root_num() == 1 && a != 0)
        return -b/(2*a);
    if(root_num() == 2)
        return (-b - pow((b*b - 4*a*c), 0.5))/(2*a);
    return -1;
}

double quadratic::root2(){
    assert(root_num() != 0);
    if(root_num() == 1 && a == 0)
        return -c/b;
    if(root_num() == 1 && a != 0)
        return -b/(2*a);
    if(root_num() == 2)
        return (-b + pow((b*b - 4*a*c), 0.5))/(2*a);
    return -1;
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