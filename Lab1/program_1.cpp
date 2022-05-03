
/*
Запрограмувати операції введення з клавіатури та виведення на екран значень змінних різних типів згідно з форматами даних (форматне введення-виведення)
і без використання форматів. Використати всі функції, що приведені у таблиці 1.2. Визначити  розбіжності  у  використанні функцій введення - виведення.
*/
#include <stdio.h>//бібілотека функцій введення і виведення
#include <iostream> //потоки виводу функції
#include <conio.h>  //функції роботи з консоллю
#include <math.h>  //бібліотека математичних функцій

using namespace std;
int main() // основна функція - точка входу до програми
{
	setlocale(LC_ALL, "Ukrainian");//задає локаль, яка буде використовуватися поточною програмою
	cout << " Lab1 task2 var-2, student: Byvalkevych Anastasia Victorivna gr-13\n\n";
	cout << " Запрограмувати операцiї введення з клавiатури та виведення на екран значень змiнних рiзних типiв згiдно з форматами даних (форматне введення-виведення) i без використання форматiв.\n Використати всi функцiї, що приведенi у таблицi 1.2. Визначити  розбiжностi  у  використаннi функцiй введення - виведення.\n\n\n ";
	_getch(); // чекати натискання на клавішу


	int y; //повідомляємо змінні
	cout << " Usage of function printf, scanf:\n"; //потоковий вивід
	printf(" Hello, everyone.\n Today you can take part in our quiz.\n\n Please, enter your age: "); // форматне виведення
	scanf_s("%d", &y); // форматне введення
	printf(" Well done!!!\n %d it's a wonderful age, you are a participant\n\n", y);
	_getch();

	cout << " Usage of function cout, cin:\n";
	_cputs(" We need some information from you:\n"); //виведення на консоль
	int s;
	cout << " Input your own symbol - ";
	cin >> s; //
	cout << " Good!\n\n";
	fflush(stdin); //очищення вхідного буфера
	_getch();

	cout << " Usage of function sscanf, sprintf, puts, gets:\n";
	int a; // опис локальниз змінних
	float b;
	char str1[15], str2[80];
	puts(" Input your key: 1=int, 2=float"); //вивід рядка
	fflush(stdin);
	gets_s(str1); //ввід рядкка
	sscanf_s(str1, "%d %f", &a, &b); //запис данниз з рядка за адресами змінних
	fflush(stdin);
	sprintf_s(str2, "a=%d b=%f -", a, b); //запис значень змінних у рядок
	puts(" Your key is: ");
	gets_s(str2);
	_getch();

	cout << " \n Usage of function putchar, getchar, putch, getch:\n";
	puts(" Input your level:");
	char c;
	c = getchar(); //ввід символу
	puts(" Great!Your level is ");
	putchar(c); //вивід символу
	fflush(stdin);
	puts(" \n Enter your the first letter of name:");
	_putch(_getch()); //ввід символу без його відображення на екрані
	fflush(stdin);


	cout << " \n\n Usage of function _cputs: ";
	char str[20];
	_cputs("\n Do you like our questionnaire? \n"); //виведення на консоль рядка
	gets_s(str, 20);
	_getch();

	cout << " \n\n Usage of function _cprintf, _cscanf:  \n";
	_cprintf_s(" You became a member! Rate us please.\n"); //виведення на консоль значень аргументів 
	int t;
	_cscanf_s("%d", &t); //введення з консолі значень змінних
	puts(" Thank you! See you soon.");
	return 0;
	system("pause");
}
