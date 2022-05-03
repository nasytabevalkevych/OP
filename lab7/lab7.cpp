//2.1.Створити квадратну матрицю, розмірність якої n >= 3 ввести з клавіатури.
//Передбачити меню вибору способу створення матриці : введення з клавіатури або генерація псевдовипадкових чисел.
//У створеній квадратній матриці передбачити нульові значення деяких діагональних елементів.
//Переставити рядки або стовпці матриці таким чином, щоб діагональні елементи стали ненульовими.
//Знайти максимальне значення елементів матриці, визначити його індекси.Якщо таких елементів декілька, то запам'ятати їх індекси в новому двовимірному масиві.
//Замінити усі нульові елементи матриці на значення максимального елемента.
//визначення визначника матриці використати алгоритм розкладання визначника за елементами i - го рядка або j - го стовпця

#include<iostream>
#include<math.h>
using namespace std;

//=========== прототипи функції

void welcome();       //ідентифікаія 
void menu();          //меню 
void inputMatrix();
void generateMatrix();
void Swap();
void Max_elem();
void Replace();
void Determinant();

// глобальні змінні ( функції без параметрів )
int n;                      //розмірність матриці
int command;                //команда меню
typedef int Matrix[10][10]; // тип матриці
Matrix A, temp;              // вхідна матриця
int i, j;                  //індекси матриці


void welcome()     //------identification of developer-------
{
	cout << "Lab-7, task 1-2, var-2\n";
	cout << "Developer: Byvalkevych Anastasia Victorivna, gr - 13" << endl;
	cout << "=====================================================\n\n";
	//-------content----------
	cout << "This program creates a square matrix, the dimension of which n> = 3.\n";
	cout << "You can enter numbers from the keyboard or by generating.\n";
	cout << "The program determines the maximum value.\n";
	cout << "This program replaces all zero elements of the matrix with the value of the maximum element.\n\n";
	cout << "=====================================================\n\n";
}

//функція виведення матриці
void outputMatrix()
{
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << A[i][j] << "  ";
		}
		cout << "\n";
	}

	cout << endl;
}

// функція введення матриці
void inputMatrix()
{
	cout << "Enter the elements of the matrix into " << n << "-dimension " << endl;
	cout << "We need zeros on the diagonal, so we will make them ourselves:\n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> A[i][j];
		}
	}
	A[0][0] = 0;
	A[1][1] = 0;
	cout << "--------------------------------------------------" << endl;
	outputMatrix();
	cout << "Matrix created, so you can use commands 3-6.\n";
	cout << "--------------------------------------------------" << endl;
}

// функція генерації матриці
void generateMatrix()
{
	srand((unsigned)(time(NULL))); // ініціалізація генератора випадкових чисел
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			A[i][j] = rand() % 10; // Каждый элемент случайному числу от 0 до 9
		}
	}
	A[0][0] = 0;
	A[1][1] = 0;
	outputMatrix();
	cout << "Matrix created, so you can use commands 3-6." << endl;
	cout << "--------------------------------------------------" << endl;
}

//зміна рядків, щоб на діагоналі не були нулів
void Swap()
{
	for (int i = 0; i < n; i++)
	{
		if (A[i][i] == 0)
		{
			// зміна рядків
			for (int j = 0; j < n; j++)
				swap(A[i][j], A[i + 1][j]);

			// зміна стовпців
			//for (int j = 1; j <= n; j++)
				//swap(A[j][column], A[j][n - 1]);
		}
	}
	outputMatrix();
	cout << "--------------------------------------------------" << endl;
}

//максимальне значення елементів матриці
void Max_elem()
{
	int maxi = 0, maxj = 0;
	int max = A[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (A[i][j] > A[maxi][maxj])
			{
				max = A[i][j];
				maxi = i;
				maxj = j;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (A[i][j] == A[maxi][maxj])
			{
				cout << endl << "Maximum value - " << max << "[" << i + 1 << "][" << j + 1 << "]" << endl;
			}
		}
	}
	cout << "--------------------------------------------------" << endl;
}

//замінити нульові елементи максимальним
void Replace()
{
	int max = A[0][0];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (max < A[i][j])
			{
				max = A[i][j];
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (A[i][j] == 0)
			{
				A[i][j] = max;

			}
		}
	}
	outputMatrix();
	cout << "--------------------------------------------------" << endl;
}

//фунція визначники шляхом викреслення і-рядка, j-стовця
void getMinor(Matrix A, Matrix temp, int p, int q, int n) // p - індекс рядка, q - індекс стовпця
{
	int i = 0, j = 0;
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
		{
			if (row != p && col != q)   // викреслення рядка та стовця
			{
				temp[i][j++] = A[row][col];

				if (j == n - 1)   //перехід до наступного елемента
				{
					j = 0;
					i++;
				}
			}
		}
	}
}

//функція обчислення детермінанта
int findDeterminant(Matrix A, int n)
{
	int D = 0;

	if (n == 1)
		return A[0][0];

	Matrix temp;

	int sign = 1;  // через один брати з мінусом

	for (int i = 0; i < n; i++)
	{
		getMinor(A, temp, 0, i, n);
		D += sign * A[0][i] * findDeterminant(temp, n - 1);
		sign = -sign;
	}
	return D;
}

//функція виводу детермінанта
void Determinant()
{
	int d = findDeterminant(A, n);
	cout << "\nDeterminant of a given matrix: " << d << endl;
	cout << "--------------------------------------------------" << endl;
}

//=========== меню програми====================
void menu()
{
	cout << "\n            MENU        " << endl;
	cout << "1. Init matrix from keyboard  " << endl;
	cout << "2. Generate matrix " << endl;
	cout << "3. Permutation of rows or columns " << endl;
	cout << "4. Find the maximum value of the elements " << endl;
	cout << "5. Replace all zero elements of the matrix with the value of the maximum element " << endl;
	cout << "6. The value of the determinant of the matrix" << endl;
	cout << "7. Exit program \n\n";
	cout << "--------------------------------------------------" << endl;
	do
	{
		cout << "Select command to execute." << endl;
		cin >> command;
		cout << "==================================================" << endl;
		switch (command)
		{
		case 1: inputMatrix(); break;
		case 2: generateMatrix(); break;
		case 3: Swap(); break;
		case 4: Max_elem(); break;
		case 5: Replace(); break;
		case 6: Determinant(); break;
		case 7: exit(0); break;
		default: cout << "Unknown command - repeat again" << endl; break;
		}
	} while (command != 7);
}

// головна функція
int main()
{
	welcome();
	cout << "Enter the dimension of the matrix  (n>=3):" << endl;
	cin >> n;
	cout << "--------------------------------------------------" << endl;
	while (n < 3)
	{
		cout << "Sorry, this number is not used, we need (n>=3):" << endl;
		cin >> n;
	}
	menu();
}