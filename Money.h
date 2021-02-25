//
// Created by A. Harrison Owen on 2/24/2021.
//
#include <ostream>
#ifndef CS202HW3_MONEY_MONEY_H
#define CS202HW3_MONEY_MONEY_H


class Money {
    friend std::ostream & operator<<(std::ostream &, const Money &);
    friend Money operator+(const Money &lhs, const Money &rhs);
    friend Money operator-(const Money &lhs, const Money &rhs);
public:
    Money();
    Money(int, int);
    ~Money();

    int getDollars();
    int getCents();

    Money operator-() const;
    Money & operator+=(const Money &rhs);
    Money & operator-=(const Money &rhs);
    Money & operator*=(const Money &rhs);
    Money & operator/=(const Money & rhs);


private:
    int _dollars;
    int _cents;
    double _value;
};
Money operator*(Money lhs, const Money &rhs);

#endif //CS202HW3_MONEY_MONEY_H
