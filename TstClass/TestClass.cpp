#include <iostream>
#include <chrono>
#include "class.h"
#include "TestClass.h"

using namespace std;

    void TestCup::validateSet(double price, double ob, bool type) {

        if (!orderBook.setOrder(price, ob, type))
            cout << "\nОшибка добавления заявки\n";
    }

    void TestCup::validateChange(double price, bool type) {

        if (!orderBook.chageOrder(price, type))
            cout << "\nОшибка добавления заявки\n";
    }

    void TestCup::validateDelete(double price, bool type) {

        if (!orderBook.deleteOrder(price, type))
            cout << "\nОшибка добавления заявки\n";
    }

    void TestCup::calculateSpeed(bool fl) {
        auto start = std::chrono::high_resolution_clock::now();

        orderBook.showBook(fl);

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "Время выполнения: " << duration.count() << " микросекунд" << std::endl;
    }

