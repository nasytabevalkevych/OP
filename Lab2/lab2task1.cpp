/*
��������� �������� ������� � ��������� �� �������� �� ���������, ��� ��������� � ���������.
����� �������� 1 ����� � ������� 2.1.
*/
#include <iostream> //������ ������ �������
#include <conio.h>  //�������� �������� ������ �� ������ ������
#include <math.h>  //�������� ������������ �������
#include <stdio.h> //�������� ������� �������� � ���������

using namespace std;
int main() // ������� ������� - ����� ����� �� ��������
{
	setlocale(LC_ALL, "Ukrainian");    //���� ������, ��� ���� ����������������� �������� ���������
	cout << " Lab1 task2 var-2, student: Byvalkevych Anastasia Victorivna gr-13\n\n";
	cout << " ��������� �������� �����i� � ���������i �i� �������� �� ���������, ��� ��������� � ����i�����. \
    ����� �������� 1 �����i � ������i 2.1\n";
	float a, b, y;                     //���� ��� ���������� �� ������� ������
	cout << " Solution of quadratic equation:\n";
	cout << " Define y\n\n"; // ����� ������
	cout << " y=-a, if (a>-1) and (a<0)\n";
	cout << " y=b*a, if (a>0) and (b!=0)\n";
	cout << " y=-a^2, if (a>0) and (b=0)\n";
	cout << " y=0, if a=b=0\n\n";
	cout << " Input variables a, b\n ";
	cin >> a >> b; //������ ���� ��� ����������
	if (a > -1 && a < 0) //��������� ������ �����
	{
		y = -a;
	}
	else if (a == b && b == 0) // ��������� ������ �����
	{
		y = 0;
	}
	else if (a > 0 && b == 0) //��������� ����� �����
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
	cout << "\nRezult: y=" << y; // ������� ���������
	return 0;
	system("pause"); // ����� ��������
}

     