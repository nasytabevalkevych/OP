/*1. �������� ����������� �����, ������� �������� ����� ������ � ���������.
����������� ���� ������ ������� ��������� ������: �������� � ��������� ��� ��������� ���������������� �����. 
��������� ����������� �� �������� �������� ����� �������� �� ������� �� ��������� ���������.
������� ���������, ������������ �������� �� �� �������.

2. ³���������� ����� �� ���������� ���������� (�������� ���������� - Cocktail sort) 
�� �������� ����� � ����� �� ���������� ������������ ������� ������ .
����������� ��������� �������� ���������� � ������ ��������� �������� ���������� ������.
*/

#include<iostream>
#include<math.h>
using namespace std;

//=========== ��������� �������

	void welcome();       //����������� 
	void menu();          //���� 
	void generateArray(); // ��������� ������ ����������� �������
	void outputArray();   //��������� ������
	void MinMax_even();   // ����� ���� � �� �������� � ������ ��������
	
					 
	// �������� ���� ( ������� ��� ��������� )

	int n;         // ������� �������� ������
	int arr[10];   // ������� �����
	int command;   //������� ����
	int mass[10];

    void welcome()     //------identification of developer-------
{
	cout << "Lab-6, task 1 and 2, var-2\n";
	cout << "Developer: Byvalkevych Anastasia Victorivna, gr - 13" << endl;
	cout << "=====================================================\n\n";
	               //-------content----------
	cout << "This program creates an array. Also, we have created a menu for your comfort.\n";
	cout << "You can enter numbers from the keyboard or by generating.\n";
	cout << "The program determines the maximum and minimum value among the elements with even and odd indices.\n";
    cout << "Array search by recursive linear search algorithm and Cocktail sort.\n\n";
	cout << "=====================================================\n\n";
}


	// ������� ��������� ������
	void generateArray()
	{
		srand((unsigned)(time(NULL))); // ����������� ���������� ���������� �����
		for (int i = 0; i < n; i++)
			arr[i] = rand() % 30;
		outputArray();
		cout << "Array created, so you can use commands 3-6." << endl;
		cout << "--------------------------------------------------" << endl;
	}
	
	// ������� ��������� ������
	void outputArray()
	{
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	
	// ������� ����������� ���������� �� ������������� �������� ��� ������ �������
	void MinMax_even()
	{
		min_e = arr[0];
		min_index = 0;
		max_e = arr[0];
		max_index = 0;
		cout << "Numbers with even indices:\n";
		for (int i = 0;i < n;i++)
		{
			if ((i + 1) % 2 != 0)
			{
				if (min_e > arr[i])
				{
					min_e = arr[i];
					min_index = i;
				}
				if (max_e < arr[i])
				{
					max_e = arr[i];
					max_index = i;
				}
			}
			
		}
		cout << "The min value:" << min_e << " with index=" << min_index << endl;
		cout << "The max value:" << max_e << " with index=" << max_index << endl;
		cout << "--------------------------------------------------" << endl;
    }

	// ������� ����������� ���������� �� ������������� �������� ��� �������� �������
	void MinMax_odd()
	{
		min_e = arr[0];
		min_index = 0;
		max_e = arr[0];
		max_index = 0;
        cout << "Numbers with odd indices:\n";
	    for (int i = 0;i < n;i++)
	    {
		    if ((i + 1) % 2 == 0)
		    {
			    if (min_e > arr[i])
		        {
			      min_e = arr[i];
				  min_index = i;
		        }

		        if (max_e < arr[i])
		        {
			      max_e = arr[i];
				  max_index = i;
		        }
		    }
		   
	    }
		cout << "The min value:" << min_e << " with index=" << min_index << endl;
		cout << "The max value:" << max_e << " with index=" << max_index << endl;
		cout << "--------------------------------------------------" << endl;
	}

	// ������� ������ � ����� �� ���������� ������������ ������� ������
	void linearSearch()
	{
		int value;
		cout << "Enter value for search:" << endl;
		cin >> value;
		for (int i = 0;i < n;++i)
		{
		    if (i>n)
			{
				cout << "Not found\n";
			}
			else if (arr[i] == value)
			{
				cout << "Your elelment " << value << " in array with index: " << i << endl;
				return linearSearch();
			}
			
		}   
		cout << "Not found\n";
		cout << "--------------------------------------------------" << endl;
	}

	// ������ ������ �������� ���������� ����������
	void ShowArray()
	{
		cout << "|";
		for (int i = 0; i < n; i++) {
			cout << arr[i] << "|";
		}
		cout << endl;
	}
	
	// ������� ���������� ������ �� ���������� ���������� 
	void ShakerSort(int mass[], int n)
	{
		int left = 0, right = n- 1; //��� �� ����� ������� ������
		int check = 1;  //�������� ���������

		while ((left < right) && check > 0)//���� ��� �� ����� ������� ��� �� �-�� ��������� �� = 0
		{
			check = 0;
			for (int i = left; i < right; i++) //��������� ���� �������
			{

				if (mass[i] > mass[i + 1]) //���� ��������� ������� ����� ���������
				{
					double t = mass[i];
					mass[i] = mass[i + 1]; //������� ������
					mass[i + 1] = t;
					check = 1;// 
					ShowArray();//���� �������� ����������
				}

			}
			right--; //�������� ����� ������� �� 1

			for (int i = right; i > left; i--)  //��������� ������ �����
			{

				if (mass[i - 1] > mass[i]) //���� ������� ������� ������ �� ������
				{
					double t = mass[i];
					mass[i] = mass[i - 1];// ������ ������
					mass[i - 1] = t;
					check = 1;
					ShowArray();//���� �������� ����������
				}
			}
			left++; //�������� ��� ������� �� 1
			ShowArray();//���� �������� ����������
		}
		
	}
	
	//=========== ���� ��������====================
	void menu()
	{
		cout << "\n            MENU        " << endl;
			cout << "1. Init array from keyboard  " << endl;
			cout << "2. Generate arry " << endl;
			cout << "3. Get Min and Max for even index " << endl;
			cout << "4. Get Min and Max for odd index" << endl;
			cout << "5. Cocktail sort" << endl;
			cout << "6. Search by recursive linear search algorithm" << endl;
			cout << "7. Exit program \n\n";
			cout << "--------------------------------------------------" << endl;
		do
		{
			cout << "Select command to execute." << endl;
			cin >> command;
			cout << "==================================================" << endl;
			switch (command)
			{
			case 1: inputArray(); break;
			case 2: generateArray(); break;
			case 3: MinMax_even(); break;
			case 4: MinMax_odd(); break;
			case 5: ShakerSort(arr,n);
				for (int i = 0; i < n; i++)
					cout << arr[i] << "|";//��������� ����������
				cout << endl;
				break;
			case 6: linearSearch(); break;
			case 7: exit(0); break;
			default: cout << "Unknown command - repeat again" << endl; break;
			}
		} while (command != 7);
	}

	// ������� �������
	int main()
	{
		welcome(); 
	    cout << "Enter the number of array elements  (<10):" << endl;
		cin >> n;
		cout << "--------------------------------------------------" << endl;
		while (n > 10)
		{
			cout << "Sorry, this number is not used, we need (<10):" << endl;
			cin >> n;
		}
		menu();
	}

