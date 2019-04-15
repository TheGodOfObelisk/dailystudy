#include "account.h"
#include <iostream>

using namespace std;

void account_info(account);
void account_list();

int main(){
    double balance, interest_rate;
    cout << "Please input initial balance: ";
    cin >> balance;
    cout << "Please input initial annual interest rate: ";
    cin >> interest_rate;
    account a(balance, interest_rate);
    int choice;
    bool continued = true;
    while(continued){
        account_list();
        cin >> choice;
        switch (choice)
        {
            case 1:
                double deposit;
                cout << "Please input how much to deposit: ";
                cin >> deposit;
                a.deposit(deposit);
                break;
            case 2:
                double withdrawal;
                cout << "Please input how much to withdraw: ";
                cin >> withdrawal;
                a.deposit(withdrawal);
                break;
            case 3:
                double years;
                cout << "n years passed, please input the n (double): ";
                cin >> years;
                a.add_interest2balance(years);
                break;
            case 4:
                double new_rate;
                cout << "Please input new interest rate: ";
                cin >> new_rate;
                a.set_interest_rate(new_rate);
                break;
            case 5:
                account_info(a);
                break;
            case 6:
                continued = false;
                break;
            default:
                cout << "Please input numbers between 1 and 6" << endl;
                break;
        }
    }
    return 0;
}

void account_info(account a){
    cout << "****** account info ******" << endl;
    cout << "balance = " << a.retrieve_balance() << endl;
    cout << "interest = " << a.retrieve_interest_rate() << endl;
    cout << "**************************" << endl;
}

void account_list(){
    cout << "****** please choose ******" << endl;
    cout << "1: deposit" << endl;
    cout << "2: withdrawal" << endl;
    cout << "3: n year(s) passed" << endl;
    cout << "4: set interest rate" << endl;
    cout << "5: account info" << endl;
    cout << "6: exit" << endl;
    cout << "***************************" << endl;
}