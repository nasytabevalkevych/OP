
/*
�������������� �������� �������� � ��������� �� ��������� �� ����� ������� ������ ����� ���� ����� � ��������� ����� (�������� ��������-���������)
� ��� ������������ �������. ����������� �� �������, �� �������� � ������� 1.2. ���������  ���������  �  ����������� ������� �������� - ���������.
*/
#include <stdio.h>//�������� ������� �������� � ���������
#include <iostream> //������ ������ �������
#include <conio.h>  //������� ������ � ��������
#include <math.h>  //�������� ������������ �������

using namespace std;
int main() // ������� ������� - ����� ����� �� ��������
{
	setlocale(LC_ALL, "Ukrainian");//���� ������, ��� ���� ����������������� �������� ���������
	cout << " Lab1 task2 var-2, student: Byvalkevych Anastasia Victorivna gr-13\n\n";
	cout << " �������������� ������i� �������� � ����i����� �� ��������� �� ����� ������� ��i���� �i���� ���i� ��i��� � ��������� ����� (�������� ��������-���������) i ��� ������������ ������i�.\n ����������� ��i �����i�, �� ��������i � ������i 1.2. ���������  ����i�����i  �  �����������i �����i� �������� - ���������.\n\n\n ";
	_getch(); // ������ ���������� �� ������


	int y; //����������� ����
	cout << " Usage of function printf, scanf:\n"; //��������� ����
	printf(" Hello, everyone.\n Today you can take part in our quiz.\n\n Please, enter your age: "); // �������� ���������
	scanf_s("%d", &y); // �������� ��������
	printf(" Well done!!!\n %d it's a wonderful age, you are a participant\n\n", y);
	_getch();

	cout << " Usage of function cout, cin:\n";
	_cputs(" We need some information from you:\n"); //��������� �� �������
	int s;
	cout << " Input your own symbol - ";
	cin >> s; //
	cout << " Good!\n\n";
	fflush(stdin); //�������� �������� ������
	_getch();

	cout << " Usage of function sscanf, sprintf, puts, gets:\n";
	int a; // ���� ��������� ������
	float b;
	char str1[15], str2[80];
	puts(" Input your key: 1=int, 2=float"); //���� �����
	fflush(stdin);
	gets_s(str1); //��� ������
	sscanf_s(str1, "%d %f", &a, &b); //����� ������ � ����� �� �������� ������
	fflush(stdin);
	sprintf_s(str2, "a=%d b=%f -", a, b); //����� ������� ������ � �����
	puts(" Your key is: ");
	gets_s(str2);
	_getch();

	cout << " \n Usage of function putchar, getchar, putch, getch:\n";
	puts(" Input your level:");
	char c;
	c = getchar(); //��� �������
	puts(" Great!Your level is ");
	putchar(c); //���� �������
	fflush(stdin);
	puts(" \n Enter your the first letter of name:");
	_putch(_getch()); //��� ������� ��� ���� ����������� �� �����
	fflush(stdin);


	cout << " \n\n Usage of function _cputs: ";
	char str[20];
	_cputs("\n Do you like our questionnaire? \n"); //��������� �� ������� �����
	gets_s(str, 20);
	_getch();

	cout << " \n\n Usage of function _cprintf, _cscanf:  \n";
	_cprintf_s(" You became a member! Rate us please.\n"); //��������� �� ������� ������� ��������� 
	int t;
	_cscanf_s("%d", &t); //�������� � ������ ������� ������
	puts(" Thank you! See you soon.");
	return 0;
	system("pause");
}
