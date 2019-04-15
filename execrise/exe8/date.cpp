#include "date.h"
#include <assert.h>
#include <iostream>

using namespace std;

date::date(int m, int d, int y){
    assert(m >= 1 && m <= 12);
    assert(d >= 1 && d <= 31);
    // 判断是否是闰年
    if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0){
        is_leap_year = true;
    } else {
        is_leap_year = false;
    }
    month = m;
    day = d;
    year = y;
    assert(recheck());
}

bool date::recheck(){
    if(month == 4 || month == 6 || month == 9 ||month == 11){
        if(day == 31){
            cout << "Error: this month doesn't have 31 days! " << endl;
            return false;
        }
    }
    if(month == 2){
        if((is_leap_year && day > 29) || (!is_leap_year && day > 28)){
            cout << "Error: this month doesn't have 31 days! " << endl;
            return false;
        }
    }
    return true;
}

void date::one_day_passed(){
    if(month == 2){
        if((is_leap_year && day == 29) || (!is_leap_year && day == 28)){
            month += 1;
            day = 1;
        } else {
            day += 1;
        }
    } else if(month == 4 || month == 6 || month == 9 ||month == 11){
        if(day == 30){
            month += 1;
            day = 1;
        } else {
            day += 1;
        }
    } else {
        if(month == 12 && day == 31){
            month = 1;
            day = 1;
            year += 1;
            if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
                is_leap_year = true;
            } else {
                is_leap_year = false;
            }
        } else if(day == 31){
            month += 1;
            day = 1;
        } else {
            day += 1;
        }
    }
}

void show_date(const date& a, int format){
    if(format == NUMBER_FORMAT){
        cout << "date: " << a.year << "." << a.month << "." << a.day << endl;
    } else if(format == WORD_FORMAT){
        cout << "date: " << a.year << " ";
        switch(a.month){
            case 1:
                cout << "January";
                break;
            case 2:
                cout << "February";
                break;
            case 3:
                cout << "March";
                break;
            case 4:
                cout << "April";
                break;
            case 5:
                cout << "May";
                break;
            case 6:
                cout << "June";
                break;
            case 7:
                cout << "July";
                break;
            case 8:
                cout << "August";
                break;
            case 9:
                cout << "September";
                break;
            case 10:
                cout << "October";
                break;
            case 11:
                cout << "November";
                break;
            case 12:
                cout << "December";
                break;
            default:
                cout << "Error in Month";
                break;
        }
        cout << " " << a.day << endl;
    } else {
        cout << "Incorrect format indicated." << endl;
    }
}