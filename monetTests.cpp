#include "catch.hpp"
#include "Money.h"
#include <iostream>
using std::cout;
using std::endl;

TEST_CASE("Set Money Values"){
    Money wallet;
    REQUIRE(wallet.getDollars() == 0);
    REQUIRE(wallet.getCents() == 0);
    wallet={5,25};
    REQUIRE(wallet.getDollars() == 5);
    REQUIRE(wallet.getCents() == 25);
    cout << wallet << endl;
    wallet = {12, 1};
    cout << wallet << endl;

}