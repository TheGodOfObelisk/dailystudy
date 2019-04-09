#include "random.h"
#include <iostream>

using namespace std;

void pseudorandom_generator::set_parameters(int a, int b, int c, int d){
    multiplier = a;
    increment = b;
    modulus = c;
    seed = d;
}

int pseudorandom_generator::generate_number(){
    seed = (multiplier*seed + increment)%modulus;
    cout << seed << " ";
    return seed;
}

double pseudorandom_generator::generate_double_number(){
    seed = (multiplier*seed + increment)%modulus;
    double t1 = (double)seed;
    double t2 = (double)modulus;
    cout << t1/t2 << " ";
    return t1/t2;
}