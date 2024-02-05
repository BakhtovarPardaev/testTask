#pragma once
#include <map>

using namespace std;

class Cup {
    multimap <double, double> Buy;
	multimap <double, double> Sell;

public:
	Cup();
	bool setOrder(double price, double ob, bool type);
	bool chageOrder(double price, bool type);
	bool deleteOrder(double price, bool type);
	void showBook(bool fl);
	void getSize() {
		cout <<"this size = "<< this->Buy.size() << endl;
	}
};