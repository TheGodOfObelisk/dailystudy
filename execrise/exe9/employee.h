#pragma once

class employee
{
private:
    /* data */
    char name[20];
    unsigned int ID;
    double hour_wage;
public:
    employee(/* args */);
    ~employee();
    double yearly_salary();
};

employee::employee(/* args */)
{
}

employee::~employee()
{
}
