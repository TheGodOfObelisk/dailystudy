#ifndef ACCOUNT_H
#define ACCOUNT_H

class account{
public:
    account(){
        balance = interest_rate = 0;
    }
    account(double, double);
    void set_interest_rate(double);
    void deposit(double);
    void withdrawal(double);
    void add_interest2balance(double);
    double retrieve_interest_rate() const;
    double retrieve_balance() const;
private:
    double interest_rate, balance;// annual interest rate
};

#endif