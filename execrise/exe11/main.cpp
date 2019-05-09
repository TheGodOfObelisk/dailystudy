#include "fueler.h"
#include <iostream>

using namespace std;

int main(){
    fueler a;
    a.add_im_gallons(100);
    a.add_kilometers(3214);
    a.add_liters(49);
    a.add_miles(3269);
    a.add_us_gallons(120);
    a.fueler_info();
    cout << "****** Now reset ******" << endl;
    a.add_im_gallons(60);
    a.add_kilometers(1200);
    a.add_liters(100);
    a.add_miles(4210);
    a.add_us_gallons(33);
    a.fueler_info();   
}