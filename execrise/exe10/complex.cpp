#include "complex.h"
#include <iostream>
using namespace std;

// double complex::get_imagine(){
//     return imagine;
// }

// double complex::get_real(){
//     return real;
// }

void complex::print_info(){
    if(real == 0 && imagine != 0){
        cout << imagine << "i" << endl;
        return;
    } else if(real == 0 && imagine == 0){
        cout << "0" << endl;
        return;
    }
    // 到这里real不为0
    cout << real;
    if(imagine > 0){
        cout << "+" << imagine << "i" << endl;
    } else if(imagine < 0){
        cout << "-" << imagine << "i" << endl;
    } else {
        cout << endl;
    }
    return;
}

complex operator +(const complex &a, const complex &b){
    double n = a.real + b.real;
    double m = a.imagine + b.imagine;
    return complex(n, m);
}

complex operator -(const complex &a, const complex &b){
    double n = a.real - b.real;
    double m = a.imagine - b.imagine;
    return complex(n, m);
}

complex operator *(const complex &a, const complex &b){
    double n = a.real*b.real - a.imagine*b.imagine;
    double m = a.real*b.imagine + a.imagine*b.real;
    return complex(n, m);
}

complex operator /(const complex &a, const complex &b);