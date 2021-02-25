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
    wallet = {10,99};
    wallet-={5,99};
    REQUIRE(wallet.getDollars() == 5);
    REQUIRE(wallet.getCents() == 0);
    Money temp = {2,99};
    wallet-=temp;
    REQUIRE(wallet.getDollars() == 3);
    REQUIRE(wallet.getCents() == -99);
}