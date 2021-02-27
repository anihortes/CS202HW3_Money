//
// Created by A. Harrison Owen on 2/24/2021.
//
#ifndef CS202HW3_MONEY_MONEY_H
#define CS202HW3_MONEY_MONEY_H


class Money {
    friend std::ostream & operator<<(std::ostream &, const Money &);
    friend Money operator+(const Money &lhs, const Money &rhs);
    friend Money operator-(const Money &lhs, const Money &rhs);
    friend bool operator==(const Money &lhs, const Money &rhs);
    friend bool operator<(const Money &lhs, const Money &rhs);

public:
    Money();
    Money(double);
    Money(int, int);
    ~Money();

    int getDollars();
    int getCents();

    Money operator-() const;
    Money & operator+=(const Money &rhs);
    Money & operator-=(const Money &rhs);
    Money & operator*=(const double &a);
    Money & operator/=(const double &a);
    Money & operator++();
    Money & operator++(int);
    Money & operator--();
    Money & operator--(int);
    
private:
    int _dollars;
    int _cents;
    double _value;
};
Money operator*(Money lhs, const double &a);
Money operator*(const double &a, Money rhs);
Money operator/(Money lhs, const double &a);

bool operator!=(const Money &lhs, const Money &rhs);
bool operator>(const Money &lhs, const Money &rhs);
bool operator<=(const Money &lhs, const Money &rhs);
bool operator>=(const Money &lhs, const Money &rhs);
#endif //CS202HW3_MONEY_MONEY_H
