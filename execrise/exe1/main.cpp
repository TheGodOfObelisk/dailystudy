#include "main.h"
#include <iostream>
#include <assert.h>

using namespace std;

int main(){
    statistician s;
    s.next_number(1.1);
    s.next_number(-2.4);
    s.next_number(0.8);
    s.next_number(2.1);
    s.next_number(-9);
    cout << "********************************" << endl;
    cout << "s.length: " << s.sequence_length() << endl;
    cout << "s.sum: " << s.sequence_sum() << endl;
    cout << "s.last number: " << s.sequence_last() << endl;
    cout << "s.mean: " << s.sequence_mean() << endl;
    cout << "s.min: " << s.sequence_min() << endl;
    cout << "s.max: " << s.sequence_max() << endl;
    statistician b;
    b.next_number(0.3);
    b.next_number(-0.7);
    b.next_number(3);
    cout << "********************************" << endl;
    cout << "b.length: " << b.sequence_length() << endl;
    cout << "b.sum: " << b.sequence_sum() << endl;
    cout << "b.last number: " << b.sequence_last() << endl;
    cout << "b.mean: " << b.sequence_mean() << endl;
    cout << "b.min: " << b.sequence_min() << endl;
    cout << "b.max: " << b.sequence_max() << endl;
    cout << "++++++++++++++++++++++++++++++++" << endl;
    cout << "after +" << endl;
    statistician c = s + b;
    cout << "c.length: " << c.sequence_length() << endl;
    cout << "c.sum: " << c.sequence_sum() << endl;
    cout << "c.last number: " << c.sequence_last() << endl;
    cout << "c.mean: " << c.sequence_mean() << endl;
    cout << "c.min: " << c.sequence_min() << endl;
    cout << "c.max: " << c.sequence_max() << endl;

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

statistician operator +(statistician& a, statistician& b){
    statistician c;
    if((a.sequence_length() + b.sequence_length()) == 0)
        return c;
    if(a.sequence_length() == 0)
        return b;
    else if(b.sequence_length() == 0)
        return a;
    // both a and b are non-empty
    double max = (a.sequence_max() < b.sequence_max()) ? b.sequence_max() : a.sequence_max();
    double min = (a.sequence_min() < b.sequence_min()) ? a.sequence_min() : b.sequence_min();
    // b follows after a
    int length = a.sequence_length() + b.sequence_length();
    double sum = a.sequence_sum() + b.sequence_sum();
    double last_number = b.sequence_last();
    if(last_number != max && last_number != min){
        c.next_number(max);
        c.next_number(min);
        while(c.sequence_length() != length-1){
            c.next_number((sum-min-max-last_number)/(length-3));
        }
        c.next_number(last_number);
        return c;
    } else if(last_number == max){
        c.next_number(min);
    } else {
        c.next_number(max);
    }
    while(c.sequence_length() != length-1){
        c.next_number((sum-min-max)/(length-2));
    }
    c.next_number(last_number);
    return c;
}