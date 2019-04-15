#include "account.h"
#include <assert.h>

account::account(double a, double b){
    assert(0 < b && b < 1);
    balance = a;
    interest_rate = b;
}

double account::retrieve_balance() const{
    return balance;
}

double account::retrieve_interest_rate() const{
    return interest_rate;
}

void account::set_interest_rate(double a){
    assert(0 < a && a < 1);
    interest_rate = a;
}

void account::deposit(double a){
    assert(a >= 0);
    balance += a;
}

void account::withdrawal(double a){
    assert(a >= 0);
    balance -= a;
}

void account::add_interest2balance(double years){
    // double months = years * 12;
    balance += (balance * interest_rate * years);
}