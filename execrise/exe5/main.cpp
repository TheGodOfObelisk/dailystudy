#include "random.h"
#include <iostream>

using namespace std;

int main(){
    pseudorandom_generator a(40, 725, 729, 1);
    cout << "******start to generate pseudorandom numbers******" << endl;
    int i = 0;
    while(i < 729){
        // a.generate_number();
        a.generate_double_number();
        if((i+1)%20 == 0)
            cout << "\n";
        i++;
    }
    cout << "\n******here should be numbers in [0, 1) uniquely******" << endl;
    return 0;
}