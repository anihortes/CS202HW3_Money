//
// Created by A. Harrison Owen on 2/24/2021.
//
#include <iomanip>
#include "Money.h"
#include <iostream>
#include <math.h>

Money::Money(double a) : _cents(a){
    _dollars = getDollars();
    _cents = getCents();
    int toInt = int(a);
    if(toInt/a == 1)
    _value = a/100;
    else _value = round(a*100)/100;
}

Money::Money() : _dollars(0), _cents(0), _value(0){}

Money::Money(int dollars, int cents) : _dollars(dollars), _cents(cents) {
    _value = _dollars + _cents/100;
}

Money::~Money() {}

int Money::getDollars() {
    return _cents/100;
}

int Money::getCents() {
    return _cents%100;
}

std::ostream &operator<<(std::ostream &os, const Money &money) {
    double temp = money._value;
    if (temp == 0){
        os << '$' << std::fixed << std::setprecision(2) << temp;
        return os;
    }
    if(temp < 0){
        os << '-';
        temp *= -1;
    }
        os << '$' << std::fixed << std::setprecision(2) << temp;
    return os;
}

Money Money::operator-() const {
    Money neg{ *this};
    if(_dollars != 0){
        neg._dollars *= -1;
    }
    else{
        neg._cents *= -1;
    }
    return neg;
}

Money & Money::operator+=(const Money &rhs){
    _dollars += rhs._dollars;
    _cents += rhs._cents;
    return *this;
}

Money operator+(const Money &lhs, const Money &rhs) {
    auto temp{lhs};
    temp+=rhs;
    return temp;
}

Money &Money::operator-=(const Money &rhs) {
    _dollars -= rhs._dollars;
    _cents -= rhs._cents;
    return *this;
}

Money operator-(const Money &lhs, const Money &rhs) {
    auto temp{lhs};
    temp-=rhs;
    return temp;
}

Money &Money::operator*=(const double &a){
    _dollars *= a;
    _cents *= a;
    return *this;
}

Money operator*(Money lhs, const double &a){
    return (lhs *= a);
}

Money operator*(const double &a, Money rhs){
    return (rhs *= a);
}

Money &Money::operator/=(const double &a){
    _dollars /= a;
    _cents /= a;
    return *this;
}

Money &Money::operator++() {
    return *this+={1,0};
}

Money &Money::operator++(int) {
    auto copy{*this};
    ++(*this);
    return *this;
}

Money operator/(Money lhs, const double &a){
    return (lhs /= a);
}

Money &Money::operator--() {
    return *this-={1,0};
}

Money &Money::operator--(int) {
    auto copy{*this};
    --(*this);
    return *this;
}

bool operator==(const Money &lhs, const Money &rhs) {
    return (lhs._dollars==rhs._dollars)&&(lhs._cents==rhs._cents);
}

bool operator<(const Money &lhs, const Money &rhs) {
    if(lhs._dollars==rhs._dollars){
        return lhs._cents<rhs._cents;
    }
    else {
        return lhs._dollars<rhs._dollars;
    }
}

bool operator!=(const Money &lhs, const Money &rhs) {
    return !(lhs==rhs);
}

bool operator>(const Money &lhs, const Money &rhs) {
    return rhs<lhs;
}

bool operator<=(const Money &lhs, const Money &rhs) {
    return !(lhs>rhs);
}

bool operator>=(const Money &lhs, const Money &rhs) {
    return !(rhs>lhs);
}