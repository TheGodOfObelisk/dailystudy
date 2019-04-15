#include "date.h"
#include <iostream>
#include <cassert>

using namespace std;

void print_list();

int main(){
    int day, month, year;
    cout << "Initialize Date" << endl;
    cout << "Please input year: " << endl;
    cin >> year;
    cout << "Please input month: " << endl;
    cin >> month;
    cout << "Please input day: " << endl;
    cin >> day;
    date a(month, day, year);
    bool continued = true;
    while(continued){
        int choice;
        int n;// get user input
        print_list();
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Please input the number of days: " << endl;
                cin >> n;
                assert(n > 0);
                while(n > 0){
                    a.one_day_passed();
                    n--;
                }
                break;
            case 2:
                cout << "Please input the type of output: " << endl;
                cout << "1: NUMBER FORMAT" << endl;
                cout << "2: WORD FORMAT" << endl;
                cin >> n;
                if(n == 1){
                    show_date(a, NUMBER_FORMAT);
                } else if(n == 2){
                    show_date(a, WORD_FORMAT);
                } else {
                    cout << "incorrect input, skip" << endl;
                }
                break;
            case 3:
                continued = false;
                break;
            default:
                break;
        }
    }
    return 0;
}

void print_list(){
    cout << "******operations******" << endl;
    cout << "1: n days passed" << endl;
    cout << "2. show date" << endl;
    cout << "3. exit" << endl;
    cout << "**********************" << endl;
}