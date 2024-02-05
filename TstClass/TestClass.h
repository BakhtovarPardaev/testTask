#pragma once
#include <chrono>
#include "class.h"

using namespace std;

class TestCup {
        Cup& orderBook;                                                             

    public:

        TestCup(Cup& orderBook) : orderBook(orderBook) {}                          

        void validateSet(double price, double ob, bool type);

        void validateChange(double price, bool type);

        void validateDelete(double price, bool type);

        void calculateSpeed(bool fl);
    };