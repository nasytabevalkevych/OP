#include<iostream>
#include<math.h>
#include<iomanip>
#include<float.h>
using namespace std;

float x; //параметр зовнішньої суми
float k = 0;  //параметр внутрішньої суми
float sum = 0;  //параметр ряду
float error;    //точність розрахунків
float member;   //елемент ряду


void OutputSum()
{
    cout << setw(5) << x << setw(10) << k << setw(20) << member << setw(15) << sum << endl;  // виведення поточних розрахунків
}

float factorial(int number) //обчислення факторіала числа
                            // параметр number - число, факторіал якого розраховується
{ 
    float fact = 1;
    if (number != 0)
    {
        for (int i = 1; i <= number; i++) 
        {
            fact *= i;
        }
    }
    return (float)fact;
}

void MemberAndSum()  //обчислення елементу ряду та суми
{
    float numerator;  //чисельник елемента ряду
    float denominator; //знаменник елемента ряду
    for (x = 1; x <= 5; x++) 
    {
        k = 0;
        do
        {
            numerator = (pow(-1.0, k)) * pow(x / 2, (2 * k) + 1);

            if (k > 30)
            {
                cout << "overflow - break cycle with k" << endl;
                break;
            }
            else 
            {
                denominator = (k + 1) * factorial(k);
                member = numerator / denominator;
                sum += member;
                OutputSum();
                k++;
            }
        } while (fabs(member) > error); // поки не досягнуто заданої точності
    }
}
void welcome()//------identification of developer-------
{
    cout << "Lab-4, task1, var-2\n";
    cout << "Developer: Byvalkevych Anastasia Victorivna, gr - 13" << endl;
    cout << "===================================================" << endl;
    //content
    cout << "To calculate the sum of row" << endl;
    cout << "5        endlessness   " << endl;
    cout << "sum        sum        ((-1)^k* (x/2)^(2k+1))/ (k+1)*k!" << endl;
    cout << "x=1        k=0" << endl;
}
int main() //-----головна функція
{
    welcome();
    bool answer = 0;
    do
    {
        cout << "Input error:";
        cin >> error;

        cout << "Result of iterations" << endl;
        cout << "===================================================" << endl;
        cout << "    x         k            member            sum   " << endl;
        cout << "===================================================" << endl;
        MemberAndSum();
        cout << "===================================================" << endl;
        cout << "Sum=" << sum << endl;
        sum = 0;
        error = 0;
        cout << "\nDo you want to try again? Yes=1, No=0\n";
        cin >> answer;
    } while (answer != 0);
    system("pause");
}