#include "lander.h"
#include <iostream>
#include <cassert>

double lunar_lander::get_fuel_flow_rate() const{
    return fuel_flow_rate;
}

double lunar_lander::get_fuel() const{
    return fuel;
}

double lunar_lander::get_altitude() const{
    return altitude;
}

double lunar_lander::get_lander_mass() const{
    return altitude;
}

double lunar_lander::get_vertical_speed() const{
    return vertical_speed;
}

double lunar_lander::get_max_fuel_rate() const{
    return max_fuel_rate;
}

double lunar_lander::get_max_engine_thrust() const{
    return max_engine_thrust;
}

int lunar_lander::set_fuel_flow_rate(double rate){
    assert(rate >= 0 && rate <= 1);
    fuel_flow_rate = rate;
    return 0;
}

void lunar_lander_info(lunar_lander a){
    std::cout << "fuel_flow_rate: " << a.get_fuel_flow_rate() << std::endl;
    std::cout << "fuel: " << a.get_fuel() << "kg" << std::endl;
    std::cout << "altitude: " << a.get_altitude() << "meters" << std::endl;
    std::cout << "lander_mass: " << a.get_lander_mass() << "kg" << std::endl;
    std::cout << "vertical_speed: " << a.get_vertical_speed() << "meters/sec" << std::endl;
    std::cout << "max_fuel_rate: " << a.get_max_fuel_rate() << "kg/sec" << std::endl;
    std::cout << "max_engine_thrust: " << a.get_max_engine_thrust() << "newtons" << std::endl;
}

void lunar_lander::time_pass(double time){
    std::cout << "Initial state:" << std::endl;
    lunar_lander_info(*this);
    if(fuel_flow_rate > 0 && fuel == 0){
        fuel_flow_rate = 0;
    }
    std::cout << time << " second(s) elapsed." << std::endl;
    vertical_speed += time*((fuel_flow_rate*max_engine_thrust)/(fuel+lander_mass)-1.62);
    altitude += time*vertical_speed;
    fuel -= time*fuel_flow_rate*max_fuel_rate;
    if(altitude <= 0){
        vertical_speed = altitude = 0;
    }
    if(fuel <= 0){
        fuel = 0;
    }
    std::cout << "state now:" << std::endl;
    lunar_lander_info(*this);
}