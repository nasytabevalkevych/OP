//    |(x-1)^1/2 + (x+1)^1/2, -2<x=<0
//  Y={
//    | 1/(x^2 - 1)^1/2,      0<x<2
//  x between -5, 5, step 1
//   x^1/2: y0=1, yn+1=1/2*(yn+x/yn), n=0, 1, 2...
#include<math.h> 
#include<iostream>
#include <iomanip>
using namespace std;

float y,    // ����� �� �������� �������
st,         // �������� ���������� �������
x,          // �������� �������
xn, xk,     // ���������, ������ �������� �������
err, xs,    // �������, �� ���� ���� ���������
t;          // ������� ����������
bool flag = true; // ��������� ��� ���������� ��������� ���������� �������

// ���������� ������ �� �������� �������
double my_sqrt(double x)
{
    x -= 1;
    double equotion = 1;
    double sum = 1;
    for (int n = 1; n <= 100; n++)
    {
        equotion *= (-1.0) * (2 * n - 1) * 2 * n * x / (n * n * 4);
        sum += equotion / (1.0 - 2 * n);
    }
    return sum; // ���������� �������� ������ � �������
}
void welcome()
{ //------identification of developer-------
    cout << "Lab-3, task1, var-2\n";
    cout << "Developer: Byvalkevych Anastasia Victorivna, gr - 13" << endl;
    cout << "===================================================" << endl;
    //------content--------
    cout << "To calculate root function" << endl;

}
int main() // ������� �������
{
    welcome();
    bool answer = 0;
    do
    {
        cout << "Input xn, xk, xs(-5 5 2)  \n" << endl;
        cin >> xn >> xk >> xs;
        cout << "Input t\n";
        cin >> t;

        cout << "Result of iterations:" << endl;
        cout << "=================================================================" << endl;
        cout << "       x             y               standart               error   " << endl;
        cout << "=================================================================" << endl;
        for (x = xn; x <= xk; x += xs) // ���� �������� ������� ��������� �������
        {
            if (x > -2 && x <= 0) // �������� ���� ������
            {
                y = my_sqrt(x - 1) + my_sqrt(x + 1);  //���������� ������� �� �������� �������
                st = sqrt(x - 1) + sqrt(x + 1);  // ���������� ������� �� ����������� ��������
                err = fabs(st - y);  //��������� �� ������ � ���������� ��������� �������

            }

            else if (x > 0 && x < 2)
            {
                y = 1 / my_sqrt(pow(x, 2) - 1);
                st = 1 / sqrt(pow(x, 2) - 1);
                err = fabs(st - y);
            }
            else if (x > 2 || x < -2)
                flag = false; //������� �� ���������

            if (flag) // ���� ���������, �� ������� �� ��������
            {
                cout << setw(5) << x << setw(20) << y << setw(20) << st << setw(15) << err << endl;
            }
            else // ������� �� ���������
            {
                cout << "not define\n";

            }

        }
        cout << "\nDo you want to try again? Yes=1, No=0\n";
        cin >> answer;
    } while (answer != 0);
    system("pause");
}
