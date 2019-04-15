#ifndef MY_DATE_H
#define MY_DATE_H

#define NUMBER_FORMAT 0
#define WORD_FORMAT 1

class date{
public:
    date(){
        month = 1;
        day = 1;
        year = 1900;
        is_leap_year = false;
    };
    date(int m, int d, int y);
    void one_day_passed();
    friend void show_date(const date& a, int format);
private:
    int month, day, year;
    bool is_leap_year;
    bool recheck();
};

#endif