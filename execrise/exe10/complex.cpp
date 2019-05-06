#include "complex.h"
#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

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
    if(imagine > 0 && imagine != 1){
        cout << "+" << imagine << "i" << endl;
    } else if(imagine == 1){
        cout << "+i" << endl;
    } else if(imagine < 0 && imagine != -1){
        cout << imagine << "i" << endl;
    } else if(imagine == -1){
        cout << "-i" << endl;
    } else {// imagine == 0
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

complex operator /(const complex &a, const complex &b){
    assert(!(b.real == 0 && b.real == 0));
    double n = (a.real*b.real+a.imagine*b.imagine)/(pow(b.real, 2)+pow(b.imagine, 2));
    double m = (a.imagine*b.real-a.real*b.imagine)/(pow(b.real, 2)+pow(b.imagine, 2));
    return complex(n, m);
}