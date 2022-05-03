/*
Визначити значення функції в залежності від значення її аргументу, яке вводиться з клавіатури.
Умови завдання 1 подані в таблиці 2.1.
*/
#include <iostream> //потоки виводу функції
#include <conio.h>  //бібліотека очищення єкрану та іншого сервісу
#include <math.h>  //бібліотека математичних функцій
#include <stdio.h> //бібілотека функцій введення і виведення

using namespace std;
int main() // основна функція - точка входу до програми
{
	setlocale(LC_ALL, "Ukrainian");    //задає локаль, яка буде використовуватися поточною програмою
	cout << " Lab1 task2 var-2, student: Byvalkevych Anastasia Victorivna gr-13\n\n";
	cout << " Визначити значення функцiї в залежностi вiд значення її аргументу, яке вводиться з клавiатури. \
    Умови завдання 1 поданi в таблицi 2.1\n";
	float a, b, y;                     //змінні для результату та вхідних данних
	cout << " Solution of quadratic equation:\n";
	cout << " Define y\n\n"; // умова задачі
	cout << " y=-a, if (a>-1) and (a<0)\n";
	cout << " y=b*a, if (a>0) and (b!=0)\n";
	cout << " y=-a^2, if (a>0) and (b=0)\n";
	cout << " y=0, if a=b=0\n\n";
	cout << " Input variables a, b\n ";
	cin >> a >> b; //увести данні для розрахунків
	if (a > -1 && a < 0) //обчислити перший вираз
	{
		y = -a;
	}
	else if (a == b && b == 0) // обчислити другий вираз
	{
		y = 0;
	}
	else if (a > 0 && b == 0) //обчислити третій вираз
	{
		y = pow(-a, 2);
	}
	else if (a>0 && b!=0)
	{
		y = b * a;
	}
	else
	{
		cout << "no result";
		
	}
	cout << "\nRezult: y=" << y; // вивести результат
	return 0;
	system("pause"); // кінець програми
}

     