#include <iostream>
#include"ClassTime.h"
using namespace std;

int main()
{
	Time t;
	setlocale(LC_CTYPE, "Russian");
	cout << "Стандартное время: ";
	t.printStandard();
	cout << endl;
	system("pause");
	return 0;
}
