//
// Created by A. Harrison Owen on 2/24/2021.
//
#include <ostream>
#ifndef CS202HW3_MONEY_MONEY_H
#define CS202HW3_MONEY_MONEY_H


class Money {
    friend std::ostream & operator<<(std::ostream &, const Money &);
public:
    Money();
    Money(int, int);
    ~Money();

    int getDollars();
    int getCents();

private:
    int _dollars;
    int _cents;
    double _value;
};


#endif //CS202HW3_MONEY_MONEY_H
