#include <iostream>
#include "class.h"
#include "TestClass.h"

using namespace std;

int main()
{
	system("chcp 1251");

	bool flag = true;
	bool flag2 = false;
	Cup ordBook;

	while (flag) {
		ordBook.showBook(flag2);

		TestCup a(ordBook);

		a.calculateSpeed(flag2);
		int c = 0;
		cout << "\n1 - добавить заявку\n2 - изменить заявку\n3 - удалить заявку\n4 - показать топ 10\n5 - EXIT\n";
		cin >> c;
		if (flag2) flag2 = false;

		switch (c)
		{
		case 1: {
			double pr = 0;
			double obm = 0;
			bool tp = 0;
			cout << "Введите: \nЦену  "; cin >> pr; 
			cout << "\nОбъем  "; cin >> obm;
		    cout <<"\nТип ордера (1 - Buy, 0 - Sell)\n"; cin >> tp;
			ordBook.setOrder(pr, obm, tp);
			break;
		}
		case 2: {
			double pr = 0;
			bool tp = 0;
			cout << "Введите: \nТип ордера (1 - Buy, 0 - Sell)"; cin >> tp;
			cout << "\nЦену\n"; cin >> pr;
			ordBook.chageOrder(pr, tp);
			break;
		}
		case 3: {
			double pr = 0;
			bool tp = 0;
			cout << "Введите: \nТип ордера (1 - Buy, 0 - Sell)"; cin >> tp;
			cout << "\nЦену\n"; cin >> pr;
			ordBook.deleteOrder(pr, tp);
			break;
		}
		case 4: {
			flag2 = true;
			break;
		}
		case 5: {
			flag = false;
			break;
		}
		default:
			cout << "Неверный ключ. Выберете снова\n";
		}
  }
}
