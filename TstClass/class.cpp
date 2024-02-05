#include <iostream>
#include <iomanip>
#include <ctime>
#include "class.h"

using namespace std;

Cup::Cup()
{
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
       Buy.insert(make_pair(rand() % 100 + 1, rand() % 20 +1));
       Sell.insert(make_pair(rand() % 100 + 1, rand() % 20 +1));
    }
}

bool Cup::setOrder(double price, double ob, bool type)
{
	if (type) {
		auto rez = Buy.insert(make_pair(price, ob));
		return rez->second;
	}
	else {
		auto rez = Sell.insert(make_pair(price, ob));
		return rez->second;
	}
}

bool Cup::chageOrder(double price, bool type)
{
    double newPrice = 0;
    double newOb = 0;
    bool newType = 0;

    if (type) {
        this->Buy.erase(this->Buy.find(price));
    }
    else {
        this->Sell.erase(this->Sell.find(price));
    }

    cout << "Введите новые данные: \nЦена  "; cin >> newPrice;
    cout << "\nОбъем  "; cin >> newOb;
    cout << "\nТип ордера (1 - Buy, 0 - Sell)\n"; cin >> newType;

    return this->setOrder(newPrice, newOb, newType);
}

bool Cup::deleteOrder(double price, bool type)
{
    if (type) {
        int nSize = this->Buy.size();
        this->Buy.erase(this->Buy.find(price));

        if (this->Buy.size() == nSize)
            return false;
        else
            return true;
    }
    else {
        int nSize = this->Sell.size();
        this->Sell.erase(this->Sell.find(price));

        if (this->Sell.size() == nSize)
            return false;
        else
            return true;
    }
}

void Cup::showBook(bool fl)
{
    int count = 0;


    cout <<"\n\n\n"<<setw(15) << "SELL" << std::setw(40) << "BUY" <<"\n\n";

    auto sellIterator = this->Sell.begin();
    auto buyIterator = this->Buy.begin();

    while (sellIterator != this->Sell.end() || buyIterator != this->Buy.end()) {

        if (fl) {
            if (count == 5) break;
            else count++;
        }

        if (sellIterator != this->Sell.end()) {
            std::cout << std::setw(10) << sellIterator->first << "\t" << sellIterator->second;
            ++sellIterator;
        }
        else {
            std::cout << std::setw(10) << "\t\t";
        }

        if (buyIterator != this->Buy.end()) {
            std::cout << std::setw(35) << buyIterator->first << "\t" << buyIterator->second;
            ++buyIterator;
        }

        cout<<"\n\n\n";
    }
}
