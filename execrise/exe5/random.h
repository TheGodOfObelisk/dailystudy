#ifndef RANDOM_H
#define RANDOM_H

class pseudorandom_generator{
public:
    pseudorandom_generator(int a, int b, int c, int d){
        multiplier = a;
        increment = b;
        modulus = c;
        seed = d;
    };
    void set_parameters(int a, int b, int c, int d);
    int generate_number();
    double generate_double_number();
    double generate_gaussian_sequence();
private:
    int multiplier, seed, increment, modulus;
};

#endif