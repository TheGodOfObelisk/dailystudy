#include "complex.h"
#include <iostream>

using namespace std;

int main(){
    complex a = complex(7, 1);// 7+i
    complex b = complex(3, 4);// 3+4i
    complex c;
    cout << "a = ";
    a.print_info();
    cout << "b = ";
    b.print_info();
    cout << "c = a + b = ";
    c = a + b;
    c.print_info();
    cout << "c = a - b = ";
    c = a - b;
    c.print_info();
    cout << "c = a * b = ";
    c = a * b;
    c.print_info();
    cout << "c = a / b = ";
    c = a / b;
    c.print_info();
    return 0;
}