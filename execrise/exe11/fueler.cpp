#include "fueler.h"
#include <iostream>
#include <cassert>

using namespace std;

void fueler::reset_fueler(){
    fuel = distance = 0;
}

void fueler::add_miles(double miles){
    assert(miles >= 0);
    distance += miles * 1.609;
}

void fueler::add_kilometers(double kilometers){
    assert(kilometers >= 0);
    distance += kilometers;
}

void fueler::add_us_gallons(double usgallons){
    assert(usgallons >= 0);
    fuel += usgallons * 3.785;
}

void fueler::add_im_gallons(double imgallons){
    assert(imgallons >= 0);
    fuel += imgallons * 4.546;
}

void fueler::add_liters(double liters){
    assert(liters >= 0);
    fuel += liters;
}

void fueler::fueler_info(){
    cout << "Fueler Status: " << endl;
    cout << "distance = " << get_km() << " kilometers = " << get_miles() 
         << " miles." << endl;
    cout << "fuel = " << get_liters() << " liters = " << get_usgallons() 
         << " U.S. gallons = " << get_imgallons() << " Imperial gallons." << endl;
    cout << "fuel mileage = " << get_usmpg() << " U.S. mpg = " << get_immpg() 
         << " U.S. mpg = " << get_km_per_liters() << " km per liters." << endl;
    cout << "fuel mileage = " << get_liters_per_100km() << " liters per 100 km." << endl;
}

double fueler::get_miles() const{
    return distance / 1.609;
}

double fueler::get_km() const{
    return distance;
}

double fueler::get_usgallons() const{
    return fuel / 3.785;
}

double fueler::get_imgallons() const{
    return fuel / 4.546;
}

double fueler::get_liters() const{
    return fuel;
}

double fueler::get_usmpg() const{
    return (distance / 1.609) / (fuel / 3.785);
}

double fueler::get_immpg() const{
    return (distance / 1.609) / (fuel / 4.546);
}

double fueler::get_km_per_liters() const{
    return distance / fuel;
}

double fueler::get_liters_per_100km() const{
    if(get_km_per_liters() == 0) return 0;
    return 100 / get_km_per_liters();
}