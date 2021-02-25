//
// Created by A. Harrison Owen on 2/24/2021.
//

#include "Money.h"

Money::Money() : _dollars(0), _cents(0){}

Money::Money(int dollars, int cents) : _dollars(dollars), _cents(cents) {
    _value = _dollars + _cents/100;
}

Money::~Money() {}

int Money::getDollars() {
    return _dollars;
}

int Money::getCents() {
    return _cents%100;
}

std::ostream &operator<<(std::ostream &os, const Money &money) {
    if (money._value == 0){
        os << "$0.00";
    }
    else if(money._value < 0){
        os << "$-" << money._dollars << "." << money._cents;
    }
    else {
        os << "$" << money._dollars << "." << money._cents;
    }
    return os;
}




