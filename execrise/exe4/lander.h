#ifndef LANDER_H
#define LANDER_H

class lunar_lander{
public:
    // constructor
    lunar_lander(){
        fuel_flow_rate = 0;// between 0 and 1
        vertical_speed = 0;
        altitude = 1000;
        fuel = 1700;
        lander_mass = 900;
        max_fuel_rate = 10;// value, don't need to be between 0 and 1
        max_engine_thrust = 5000;
    };
    // constant member functions
    double get_fuel_flow_rate() const;
    double get_vertical_speed() const;
    double get_altitude() const;
    double get_fuel() const;
    double get_lander_mass() const;
    double get_max_fuel_rate() const;
    double get_max_engine_thrust() const;
    // modification member functions
    int set_fuel_flow_rate(double rate);
    void time_pass(double time);
private:
    double fuel_flow_rate;
    double vertical_speed;
    double altitude;
    double fuel;
    double lander_mass;
    double max_fuel_rate;
    double max_engine_thrust;
};

#endif