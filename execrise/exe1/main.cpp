#include "main.h"
#include <iostream>
#include <assert.h>

using namespace std;

int main(){
    statistician s;
    cout << "before insert" << endl;
    cout << "length: " << s.sequence_length() << endl;
    cout << "sum: " << s.sequence_sum() << endl;
    cout << "last number: " << s.sequence_last() << endl;
    s.next_number(1.1);
    s.next_number(-2.4);
    s.next_number(0.8);
    s.next_number(2.1);
    s.next_number(-9);
    cout << "********************************" << endl;
    cout << "length: " << s.sequence_length() << endl;
    cout << "sum: " << s.sequence_sum() << endl;
    cout << "last number: " << s.sequence_last() << endl;
    cout << "mean: " << s.sequence_mean() << endl;
    cout << "min: " << s.sequence_min() << endl;
    cout << "max: " << s.sequence_max() << endl;
    s.erase();
    cout << "********************************" << endl;
    cout << "after erase" << endl;
    cout << "length: " << s.sequence_length() << endl;
    cout << "sum: " << s.sequence_sum() << endl;
    return 0;
}

void statistician::next_number(double num){
    length++;
    sum += num;
    if(min > num)
        min = num;
    if(max < num)
        max = num;
    last_num = num;
}

int statistician::sequence_length(){
    return length;
}

double statistician::sequence_sum(){
    return sum;
}

double statistician::sequence_last(){
    assert(length > 0);
    return last_num;
}

double statistician::sequence_mean(){
    assert(length > 0);
    return sum/length;
}

double statistician::sequence_min(){
    assert(length > 0);
    return min;
}

double statistician::sequence_max(){
    assert(length > 0);
    return max;
}

void statistician::erase(){
    length = min = max = sum = last_num = 0;
}