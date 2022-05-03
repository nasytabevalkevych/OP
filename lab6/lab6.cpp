/*������ � ��������� ��������� �� ���������� ���� ������� � n- ������ �������, n >2.
��������� �� ������� �� �����:
1.���� �������;
2.������ �������;
3.������� ���� �� ����;
4.��������� �������;
5.��������� �������.
*/
#include<iostream>
#include<math.h>
using namespace std;

int n;            //��������� ��������
double vec1[10];
double vec2[10];
double vec3[10]; 
double sum;       //��������� �������
double mod1 = 0;  //������� ������� �������
double mod2 = 0;  //������� ������� �������
int command;      //������� ����

//=========== ��������� �������
void welcome();       //����������� 
void menu();          //���� 
void inputcoordnt();  // ������� ��������� �������
void Sumvec();        //���������� ���� �������
void Differvec();     //���������� ������ �������
void Scalar();        //���������� ���������� �������
void Cosvec();        //���������� �������� ���� �� ���������
void Vectfunc();      //���������� ���������� �������

void welcome()     //------identification of developer-------
{
	cout << "Lab-6, task 3, var-2\n";
	cout << "Developer: Byvalkevych Anastasia Victorivna, gr - 13" << endl;
	cout << "=====================================================\n\n";
	//-------content----------
	cout << "This program will solve given actions with vectors.\n";
	cout << "You can enter coordinates of two vectors in n-world space from the keyboard.\n";
	cout << "And select action from the menu.\n\n";
	cout << "=====================================================\n\n";
}

// ������� �������� ���������
void inputcoordnt() 
{
	cout << "Enter enter the coordinates for the vector in " << n << "-world space from the keyboard." << endl;
	cout << "\nFirst vector:";
	for (int i = 0; i < n; i++)
	{
		cin >> vec1[i];
	}
	cout << "Second vector:";
	for (int i = 0; i < n; i++)
	{
		cin >> vec2[i];
	}
	    cout << "\nWe got your coordinates, so you can use commands 1-5.\n";
	    cout << "--------------------------------------------------" << endl;
    
}

//������� ���������� ���� �������
void Sumvec()
{
    cout << "Sum of vectors = vec3 = ";
	for (int i = 0; i < n; i++)
	{
		 vec3[i] = (vec1[i] + vec2[i]);
         cout <<" "<< vec3[i];
	}
	cout << "\n--------------------------------------------------" << endl;
}

//������� ���������� ������ �������
void Differvec()
{
	cout << "Difference vectors  = vec3 =";
	for (int i = 0; i < n; i++)
	{
		vec3[i] = (vec1[i] - vec2[i]);
		cout <<" "<< vec3[i];
	}
	cout << "\n--------------------------------------------------" << endl;
}

//������� ���������� ���������� �������
void Scalar()
{
	double sum = 0;
	cout << "Scalar product of vectors = ";
	for (int i = 0; i < n; i++)
	{
		sum = sum + vec1[i] * vec2[i];
	}
	cout << sum << endl;;
	cout << "--------------------------------------------------" << endl;
}

//������� ���������� �������� ���� �� ���������
void Cosvec()
{
	double cos;
	    cout << "         vec1*vec2\n";
		cout << "cos a = ------------\n";
		cout << "        |vec1|*|vec2|\n ";
		cout << "--------------------------------------------------" << endl;
	cout << "1.First, we find the length of the vectors for the formula\n";
	cout << "  Length of the first vector:";
	for (int i = 0; i < n; i++)
	{
		mod1 = sqrt(pow(mod1, 2) + pow(vec1[i], 2));
		mod2 = sqrt(pow(mod2, 2) + pow(vec2[i], 2));
	}
	cout << mod1;
	cout << "\n  Length of the second vector:";
    cout << mod2;
	cout << "\n\n2.Second we need scalar product of vectors for the formula\n";
	Scalar();
	cos = sum / (mod1 * mod2);
	cout << "The cosine of the angle between vectors = ";
	cout << cos;
	cout << "\n--------------------------------------------------" << endl;
}

//������� ���������� ���������� �������
void Vectfunc()
{
	double vect;
	double sin;
	cout << "Vector product of vectors:\n\n";
	cout << "vec3 = |vec1*vec2| = |vec1|*|vec2|*sin a\n\n";
	cout << "        |vec1|*|vec2|\n";
	cout << "sin a = ------------\n";
	cout << "         vec1*vec2\n ";
	cout << "--------------------------------------------------" << endl;
	cout << "1.First, we find the length of the vectors for the formula\n";
	cout << "  Length of the first vector:";
	for (int i = 0; i < n; i++)
	{
		mod1 = sqrt(pow(mod1, 2) + pow(vec1[i], 2));
		mod2 = sqrt(pow(mod2, 2) + pow(vec2[i], 2));
	}
	cout << mod1;
	cout << "\n  Length of the second vector:";
	cout << mod2;
	cout << "\n2.Second we need scalar product of vectors for the formula\n";
	Scalar();
	sin = (mod1 * mod2)/sum;
	cout << "The sinus of the angle between vectors = ";
	cout << sin;
	cout << "\n--------------------------------------------------" << endl;
	cout << "Vector product of vectors:\n";
	vect = (mod1 * mod2) * sin;
	cout << vect;
	cout << "\n--------------------------------------------------" << endl;
}

void menu()
{
	cout << "\n            MENU        " << endl;
	cout << "1. Init coordinates from keyboard" << endl;
	cout << "2. Sum of vectors  " << endl;
	cout << "3. Difference vectors " << endl;
	cout << "4. Scalar product of vectors " << endl;
	cout << "5. The cosine of the angle between them" << endl;
	cout << "6. Vector product of vectors" << endl;
	cout << "7. Exit program \n\n";
	cout << "--------------------------------------------------" << endl;
	do
	{
		cout << "Select command to execute." << endl;
		cin >> command;
		cout << "==================================================" << endl;
		switch (command)
		{
		case 1: inputcoordnt(); break;
		case 2: Sumvec(); break;
		case 3: Differvec(); break;
		case 4: Scalar(); break;
		case 5: Cosvec(); break;
		case 6: Vectfunc(); break;
		case 7: exit(0); break;
		default: cout << "Unknown command - repeat again" << endl; break;
		}
	} while (command != 7);
}

int main()
{
	welcome();
	cout << "Enter the dimension of the space from the keyboard (n>2):" << endl; 
	cin >> n;     //�������� ��������� ��������
	cout << "--------------------------------------------------" << endl;
	while (n < 2)
	{
		cout << "Sorry, this number is not used, we need (n>2):" << endl;
		cin >> n;
	}
	menu();
}


