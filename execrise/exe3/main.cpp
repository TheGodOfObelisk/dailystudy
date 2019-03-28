#include <iostream>
#include "quadratic.h"

void quadratic_info(quadratic);

int main(){
    quadratic a;
    a.set_coefficients(8, 2, 3);
    quadratic_info(a);
    std::cout << "when x = 3, gets " << a.evaluate_exp(3) << std::endl;
    quadratic b;
    b.set_coefficients(4.4, 3, -1);
    quadratic_info(b);
    std::cout << "when x = 3, gets " << b.evaluate_exp(3) << std::endl;
    quadratic c;
    c = a + b;
    quadratic_info(c);
    std::cout << "when x = 6, gets " << c.evaluate_exp(6) << std::endl;
    c = 3 * c;
    quadratic_info(c);
    std::cout << "when x = -2, gets " << c.evaluate_exp(-2) << std::endl;
    return 0;
}

void quadratic_info(quadratic a){
    std::cout << "quadratic info:" << std::endl;
    std::cout << "a = " << a.get_a() << ", b = " << a.get_b() << ", c = " << a.get_c() << "." << std::endl;
}