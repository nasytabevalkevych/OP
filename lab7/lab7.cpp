//2.1.�������� ��������� �������, ��������� ��� n >= 3 ������ � ���������.
//����������� ���� ������ ������� ��������� ������� : �������� � ��������� ��� ��������� ���������������� �����.
//� �������� ��������� ������� ����������� ������ �������� ������ ����������� ��������.
//����������� ����� ��� ������� ������� ����� �����, ��� ��������� �������� ����� �����������.
//������ ����������� �������� �������� �������, ��������� ���� �������.���� ����� �������� �������, �� �����'����� �� ������� � ������ ����������� �����.
//������� �� ������ �������� ������� �� �������� ������������� ��������.
//���������� ���������� ������� ����������� �������� ����������� ���������� �� ���������� i - �� ����� ��� j - �� �������

#include<iostream>
#include<math.h>
using namespace std;

//=========== ��������� �������

void welcome();       //����������� 
void menu();          //���� 
void inputMatrix();
void generateMatrix();
void Swap();
void Max_elem();
void Replace();
void Determinant();

// �������� ���� ( ������� ��� ��������� )
int n;                      //��������� �������
int command;                //������� ����
typedef int Matrix[10][10]; // ��� �������
Matrix A, temp;              // ������ �������
int i, j;                  //������� �������


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

//������� ��������� �������
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

// ������� �������� �������
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

// ������� ��������� �������
void generateMatrix()
{
	srand((unsigned)(time(NULL))); // ����������� ���������� ���������� �����
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			A[i][j] = rand() % 10; // ������ ������� ���������� ����� �� 0 �� 9
		}
	}
	A[0][0] = 0;
	A[1][1] = 0;
	outputMatrix();
	cout << "Matrix created, so you can use commands 3-6." << endl;
	cout << "--------------------------------------------------" << endl;
}

//���� �����, ��� �� ������� �� ���� ����
void Swap()
{
	for (int i = 0; i < n; i++)
	{
		if (A[i][i] == 0)
		{
			// ���� �����
			for (int j = 0; j < n; j++)
				swap(A[i][j], A[i + 1][j]);

			// ���� ��������
			//for (int j = 1; j <= n; j++)
				//swap(A[j][column], A[j][n - 1]);
		}
	}
	outputMatrix();
	cout << "--------------------------------------------------" << endl;
}

//����������� �������� �������� �������
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

//������� ������ �������� ������������
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

//������ ���������� ������ ����������� �-�����, j-������
void getMinor(Matrix A, Matrix temp, int p, int q, int n) // p - ������ �����, q - ������ �������
{
	int i = 0, j = 0;
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
		{
			if (row != p && col != q)   // ����������� ����� �� ������
			{
				temp[i][j++] = A[row][col];

				if (j == n - 1)   //������� �� ���������� ��������
				{
					j = 0;
					i++;
				}
			}
		}
	}
}

//������� ���������� �����������
int findDeterminant(Matrix A, int n)
{
	int D = 0;

	if (n == 1)
		return A[0][0];

	Matrix temp;

	int sign = 1;  // ����� ���� ����� � ������

	for (int i = 0; i < n; i++)
	{
		getMinor(A, temp, 0, i, n);
		D += sign * A[0][i] * findDeterminant(temp, n - 1);
		sign = -sign;
	}
	return D;
}

//������� ������ �����������
void Determinant()
{
	int d = findDeterminant(A, n);
	cout << "\nDeterminant of a given matrix: " << d << endl;
	cout << "--------------------------------------------------" << endl;
}

//=========== ���� ��������====================
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

// ������� �������
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