#include <iostream>
#include "rational.h"

using namespace std;

int main(){
    rational_numbers a(2, 3);
    cout << "a = " << a << endl;
    rational_numbers b;
    cout << "please input b in the form of x/y" << endl;
    cout << "b = ";
    cin >> b;
    cout << "b = " << b << endl;
    rational_numbers c = a + b;
    cout << "c = a + b = " << c << endl;
    rational_numbers d = a - b;
    cout << "d = a - b = " << d << endl;
    rational_numbers e = a * b;
    cout << "e = a * b = " << e << endl;
    rational_numbers f = a / b;
    cout << "f = a / b = " << f << endl;
    if(a == b){
        cout << "a is equal to b." << endl;
    } else {
        cout << "a and b are unequal." << endl;
    }
    if(a > b){
        cout << "a > b is true." << endl;
    } else {
        cout << "a > b is false." << endl;
    }
    if(a < b){
        cout << "a < b is true." << endl;
    } else {
        cout << "a < b is false." << endl;
    }
    return 0;
}