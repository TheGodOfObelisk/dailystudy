#pragma once

class fueler{
public:
    fueler(){
        fuel = distance = 0;
    };
    void reset_fueler();
    void add_miles(double miles);
    void add_kilometers(double kilometers);
    void add_us_gallons(double usgallons);
    void add_im_gallons(double imgallons);
    void add_liters(double liters);
    void fueler_info();
private:
    double get_miles() const;
    double get_km() const;
    double get_usgallons() const;
    double get_imgallons() const;
    double get_liters() const;
    double get_usmpg() const;
    double get_immpg() const;
    double get_km_per_liters() const;
    double get_liters_per_100km() const;
    // 1 U.S. gallon = 3.785 liters
    // 1 Imperial gallon = 4.546 liters
    double fuel;// liters
    // 1 mile = 1.609 km
    double distance;// kilometers
};