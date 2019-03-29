#ifndef QUADRATIC_H
#define QUADRATIC_H

class quadratic{
public:
    quadratic(){
        a = b = c = 0;
    };
    void set_coefficients(double m, double n, double q);
    double get_a() const;
    double get_b() const;
    double get_c() const;
    double evaluate_exp(double x);
    int root_num();
    double root1();
    double root2();
private:
    double a, b, c;
};

quadratic operator +(const quadratic& q1, const quadratic& q2);
quadratic operator *(double r, const quadratic& q);

#endif