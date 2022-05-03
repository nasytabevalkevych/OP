/*
Розв'язати геометричну або логічну задачу. Умови завдання 2 подані в таблиці 2.2
*/
#include <iostream> //потоки виводу функції
#include <conio.h>  //бібліотека очищення єкрану та іншого сервісу
#include <math.h>  //бібліотека математичних функцій
#include <stdio.h> //бібілотека функцій введення і виведення

using namespace std;
int main() // основна функція - точка входу до програми
{
	setlocale(LC_ALL, "Ukrainian");//задає локаль, яка буде використовуватися поточною програмою
	cout << " Lab1 task2 var-2, student: Byvalkevych Anastasia Victorivna gr-13\n\n";
	cout << " Точка площини задана декартовими координатами (х, у). Перевiрити, чи належить вона кiльцю, з центром у початку координат,\
    внутрiшнiм радiусом 1 i зовнiшнiм 2.\n\n";
	float x, y, a;   //змінні для результату та вхідних данних
	cout << " Input variables point coordinates x, y\n "; // умова задачі
	cin >> x >> y; //увести данні для розрахунків
	a = pow(x, 2) + pow(y, 2);
	cout << "х ^ 2 + y ^ 2 =" << a << endl;
	cout << " Rezult is \n" ; // вивести результат
	if (pow(x, 2) + pow(y, 2) > 1 && pow(x, 2) + pow(y, 2) < 2) //обчислити вираз
	{
		cout << " Point in the ring";
	}
	else
	{
		cout << "POINT OUT OF RING";
	}
	return 0;
	system("pause");
}
