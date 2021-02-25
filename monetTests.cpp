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
    wallet = -wallet;
    REQUIRE(wallet.getDollars() == -5);
    wallet+={5,0};
    REQUIRE(wallet.getDollars() == 0);
    Money negWallet = -wallet;
    wallet = wallet+negWallet;
    REQUIRE(wallet.getDollars() == 0);
    REQUIRE(wallet.getCents() == 0);

}