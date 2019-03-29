#include <iostream>
#include "quadratic.h"

void quadratic_info(quadratic);
void quadratic_roots(quadratic);

int main(){
    quadratic a;
    a.set_coefficients(1, 2, 1);
    quadratic_info(a);
    std::cout << "when x = 3, gets " << a.evaluate_exp(3) << std::endl;
    quadratic_roots(a);
    quadratic b;
    b.set_coefficients(0, 3, -1);
    quadratic_info(b);
    std::cout << "when x = 3, gets " << b.evaluate_exp(3) << std::endl;
    quadratic_roots(b);
    quadratic c;
    c = a + b;
    quadratic_info(c);
    std::cout << "when x = 6, gets " << c.evaluate_exp(6) << std::endl;
    quadratic_roots(c);
    c = 3 * c;
    quadratic_info(c);
    std::cout << "when x = -2, gets " << c.evaluate_exp(-2) << std::endl;
    quadratic_roots(c);
    quadratic d;
    d.set_coefficients(0, 0, -1);
    quadratic_info(d);
    std::cout << "when x = 3, gets " << d.evaluate_exp(3) << std::endl;
    quadratic_roots(d);
    quadratic e;
    e.set_coefficients(0, 0, 0);
    quadratic_info(e);
    std::cout << "when x = 3, gets " << e.evaluate_exp(3) << std::endl;
    quadratic_roots(e);
    return 0;
}

void quadratic_info(quadratic a){
    std::cout << "quadratic info:" << std::endl;
    std::cout << "a = " << a.get_a() << ", b = " << a.get_b() << ", c = " << a.get_c() << "." << std::endl;
}

void quadratic_roots(quadratic a){
    switch(a.root_num()){
        case 0:
            std::cout << "This quadratic has no roots at all." << std::endl;
            break;
        case 1:
            std::cout << "This quadratic has only one root and it is " << a.root1() << "." << std::endl;
            break;
        case 2:
            std::cout << "This quadratic has two roots and they are " << a.root1() << " and " << a.root2() << "." << std::endl;
            break;
        case 3:
            std::cout << "This quadratic has infinite roots." << std::endl;
            break;
        default:
            std::cout << "Unexpected error!" << std::endl;
    }
}