#include "random.h"
#include <iostream>
#include <cmath>

using namespace std;
int ne = 0;
void pseudorandom_generator::set_parameters(int a, int b, int c, int d){
    multiplier = a;
    increment = b;
    modulus = c;
    seed = d;
}

int pseudorandom_generator::generate_number(){
    seed = (multiplier*seed + increment)%modulus;
    // cout << seed << " ";
    return seed;
}

double pseudorandom_generator::generate_double_number(){
    seed = (multiplier*seed + increment)%modulus;
    double t1 = (double)seed;
    double t2 = (double)modulus;
    // cout << t1/t2 << " ";
    return t1/t2;
}

double pseudorandom_generator::generate_gaussian_sequence(){
    // I think that median is 0.5
    double a[10] = {0};
    int i = 0;
    for(; i < 10; i++){
        a[i] = generate_double_number();
    }
    double avg = 0, sd = 0, s = 0;
    for(i = 0; i < 10; i++){
        avg += a[i];
    }
    avg /= 10;
    for(i = 0; i < 10; i++){
        s += pow(a[i]-avg, 2);
    }
    s /= 10;
    sd = sqrt(s);
    if((0.8 + (10 * avg - 6) * sd) < 0)
        ne++;
    return (0.8 + (10 * avg - 6) * sd);
    // return (avg + (10 * avg - 6) * sd);
}