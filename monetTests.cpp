#include "catch.hpp"
#include "Money.h"
#include <iostream>
using std::cout;
using std::endl;
#include <sstream>
TEST_CASE("Set Money Values"){
    Money wallet;
    REQUIRE(wallet.getDollars() == 0);
    REQUIRE(wallet.getCents() == 0);
    std::ostringstream out;
    out << wallet;
    REQUIRE(out.str() == "$0.00");
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
    temp*=temp;
    REQUIRE(temp.getDollars() == 4);
    REQUIRE(temp.getCents() == 1);
    temp = wallet*temp;
    REQUIRE(temp.getDollars()==12);
    REQUIRE(temp.getCents() == -99);
    wallet /= wallet;
    REQUIRE(wallet.getDollars() == 1);
    REQUIRE(wallet.getCents() == 1);
    temp = temp/wallet;
    REQUIRE(temp.getDollars() == 12);
    REQUIRE(temp.getCents() == -99);
    wallet++;
    REQUIRE(wallet.getDollars() == 2);
    ++wallet;
    REQUIRE(wallet.getDollars() == 3);
    wallet--;
    REQUIRE(wallet.getDollars() == 2);
    --wallet;
    REQUIRE(wallet.getDollars() == 1);
}
TEST_CASE("Booleans with Money"){
    Money wallet1 = {3,99};
    Money wallet2 = {3,99};
    REQUIRE(wallet1 == wallet2);
    ++wallet1;
    REQUIRE(wallet2<wallet1);
    REQUIRE(wallet1 != wallet2);
    REQUIRE(wallet1>wallet2);
    wallet2++;
    REQUIRE(wallet1++ >= wallet2);
    REQUIRE(wallet2++ <= wallet2);
}