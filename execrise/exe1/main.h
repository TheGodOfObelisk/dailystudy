#ifndef MY_MAIN_H
#define MY_MATH_H

class statistician{
public:
    statistician(){
        length = min = max = sum = last_num = 0;
    };
    void next_number(double num);
    int sequence_length();
    double sequence_sum();
    double sequence_last();
    double sequence_mean();
    double sequence_min();
    double sequence_max();
    void erase();
private:
    int length;
    double min, max, sum, last_num;
};

statistician operator +(statistician& a, statistician& b);

#endif