#include<math.h>
#include<iostream>

using namespace std;

void welcome()
{
    cout << "Lab4 task2 var-2, developer: Byvalkevych Anastasia Victorivna gr-13" << endl;
    cout << "===================================================================\n" << endl;
    //content
    cout << "Chain fractions" << endl;
}

int main()
{
    welcome();
    bool answer = 0;
    do {
     // ======= ���������� � ������� �������� � =====
    double a;
    cout << "Enter number a:\n";
    cin >> a;
    //  �������� ���������� ������� �����
    double curr = a * a + 256.0 / (a * a);
    double prev = 0.0;
    //  �������� �� ������ 2 �� 2^7 �� 2^1
    for (int i = 128; i >= 2;i >>= 1)
    {
        swap(curr, prev); // ������� �������� ��� ���������
        curr = a * a + double(i) / prev;
        prev = 1.0 / curr;
    }
    cout << "S=" << prev << endl; // �������� ���������
    cout << "\nDo you want to try again? Yes=1, No=0\n";
    cin >> answer;
} while (answer != 0);
system("pause");
    }
    