#include "random.h"
#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

const int NUM = 10;

enum Range{
    R1, R2, R3, R4, R5, R6, R7, R8, R9, R10
};

unsigned int range[NUM] = {0};

void update_list(double r);
void print_list();

extern int ne;

int main(){
    pseudorandom_generator a(40, 725, 729, 1);
    cout << "Test 1: multiplier = 40, increment = 725, modulus = 729, seed = 1" << endl;
    int i = 0;
    while(i < 1000000){
        // a.generate_number();
        // double r = a.generate_double_number();
        double r = a.generate_gaussian_sequence();
        update_list(r);
        i++;
    }
    print_list();
    cout << ne << endl;
    return 0;
}

void update_list(double r){
    if(r >= 0 && r < 0.1){
        range[R1] += 1;
    } else if(r >= 0.1 && r < 0.2){
        range[R2] += 1;
    } else if(r >= 0.2 && r < 0.3){
        range[R3] += 1;
    } else if(r >= 0.3 && r < 0.4){
        range[R4] += 1;
    } else if(r >= 0.4 && r < 0.5){
        range[R5] += 1;
    } else if(r >= 0.5 && r < 0.6){
        range[R6] += 1;
    } else if(r >= 0.6 && r < 0.7){
        range[R7] += 1;
    } else if(r >= 0.7 && r < 0.8){
        range[R8] += 1;
    } else if(r >= 0.8 && r < 0.9){
        range[R9] += 1;
    } else if(r >= 0.9 && r < 1.0){
        range[R10] += 1;
    }
}

void print_list(){
    cout << "------------------------------------" << endl;
    cout << setiosflags(ios::left) << setw(14) << "Range" << resetiosflags(ios::left)
         << setiosflags(ios::right) << setw(9) << "Number of Occurrences" << resetiosflags(ios::right) << endl;
    cout << "------------------------------------" << endl;
    for(int i = R1; i <= R10; i++){
        switch(i){
            case R1:
                cout << setiosflags(ios::left) << setw(14) << "[0.0, 0.1)" << resetiosflags(ios::left)
                     << setiosflags(ios::right) << setw(9) << range[R1] << resetiosflags(ios::right) << endl;
                break;
            case R2:
                cout << setiosflags(ios::left) << setw(14) << "[0.1, 0.2)" << resetiosflags(ios::left)
                     << setiosflags(ios::right) << setw(9) << range[R2] << resetiosflags(ios::right) << endl;
                break;
            case R3:
                cout << setiosflags(ios::left) << setw(14) << "[0.2, 0.3)" << resetiosflags(ios::left)
                     << setiosflags(ios::right) << setw(9) << range[R3] << resetiosflags(ios::right) << endl;
                break;
            case R4:
                cout << setiosflags(ios::left) << setw(14) << "[0.3, 0.4)" << resetiosflags(ios::left)
                     << setiosflags(ios::right) << setw(9) << range[R4] << resetiosflags(ios::right) << endl;
                break;
            case R5:
                cout << setiosflags(ios::left) << setw(14) << "[0.4, 0.5)" << resetiosflags(ios::left)
                     << setiosflags(ios::right) << setw(9) << range[R5] << resetiosflags(ios::right) << endl;
                break;
            case R6:
                cout << setiosflags(ios::left) << setw(14) << "[0.5, 0.6)" << resetiosflags(ios::left)
                     << setiosflags(ios::right) << setw(9) << range[R6] << resetiosflags(ios::right) << endl;
                break;
            case R7:
                cout << setiosflags(ios::left) << setw(14) << "[0.6, 0.7)" << resetiosflags(ios::left)
                     << setiosflags(ios::right) << setw(9) << range[R7] << resetiosflags(ios::right) << endl;
                break;
            case R8:
                cout << setiosflags(ios::left) << setw(14) << "[0.7, 0.8)" << resetiosflags(ios::left)
                     << setiosflags(ios::right) << setw(9) << range[R8] << resetiosflags(ios::right) << endl;
                break;
            case R9:
                cout << setiosflags(ios::left) << setw(14) << "[0.8, 0.9)" << resetiosflags(ios::left)
                     << setiosflags(ios::right) << setw(9) << range[R9] << resetiosflags(ios::right) << endl;
                break;
            case R10:
                cout << setiosflags(ios::left) << setw(14) << "[0.9, 1.0)" << resetiosflags(ios::left)
                     << setiosflags(ios::right) << setw(9) << range[R10] << resetiosflags(ios::right) << endl;
                break;
        }
    }
}
