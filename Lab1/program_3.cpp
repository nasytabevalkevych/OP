/*
Написати програму, що розв'язує задачу з математики та фізики шкільногого курсу, відповідно до варіантів таблиці 1.8:
*/

#include <iostream> //потоки виводу функції
#include <conio.h>  //функції роботи з консоллю
#include <math.h>  //бібліотека математичних функцій

using namespace std;
int main() // основна функція - точка входу до програми
{
	setlocale(LC_ALL, "Ukrainian");//задає локаль, яка буде використовуватися поточною програмою
	cout << "Lab1 task3 var-2, student: Byvalkevych Anastasia Victorivna gr-13\n\n";
	cout << "Написати програму, що розв'язує задачу з математики та фiзики шкiльногого курсу, вiдповiдно до варiантiв таблицi 1.8\n\n\n";
	float a; //повідомляємо змінні
	float b;
	float c;
	float S;
	float p;
	cout << "Enter the first side of triangle:";//потоковий вивід
	cin >> a; // потоковий ввід
	cout << "Enter the second side of triangle:";
	cin >> b;
	cout << "Enter the third side of triangle:";
	cin >> c;
	if (a == b && b == c)
	{
		cout << "it is an equilateral triangle\n";
		cout << "S = (a ^ 2 * sqrt(3)) / 4\n\n";
		S = (pow(a, 2) * sqrt(3)) / 4;
		cout << "Result S = " << S << endl;
	}
	else
	{
		cout << "it is an versatile or isosceles triangle, so use Heron's formula\n";
		cout << "S=sqrt(p*(p-a)*(p-b)*(p-c))\n\n";
		p = (a + b + c) / 2;
		S = sqrt(p * (p - a) * (p - b) * (p - c));
		cout << "Result S = " << S << endl;
	}
	return 0;
}