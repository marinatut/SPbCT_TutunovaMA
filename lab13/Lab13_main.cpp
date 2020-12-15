#include <iostream>
#include "Car.h" 
#include "Lorry.h"
using namespace std;
void f1(Car& c)
{
	c.Set_mark("Opel"); 
	cout << c;
}
//функция возвращает объект базового класса как результат
Lorry f2()
{
	Lorry l("Kia", 1, 2, 3); 
	return l;
}
int main()
{
	//работа с классом Car 
	Car a;
	cin >> a;
	cout << a;
	Car b("Ford", 4, 115); 
	cout << b;
	a = b;
	cout << a;
	//работа с классом Lorry 
	Lorry c;
	cin >> c;
	cout << c; //принцип подстановки
	f1(c);//передаем объект класса 
	a=f2();
	cout<<a;

}
