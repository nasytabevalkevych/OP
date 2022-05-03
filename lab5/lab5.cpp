/*Увести з клавіатури два натуральних числа n та m.
Обчислити кількість комбінацій з n різних елементів по m.Кількість комбінацій визначається рекурентним співвідношенням :
 k  |0, r>n>=0
C  =|1, k=n>=0 or k=0, n>0
 n  |  k-1    k
    |C    + C
 |  n-1    n-1
*/
#include<iostream>
#include<math.h>
using namespace std;
int k, n;                  // значення для введення
int depth = 0, iterat = 0; // глубина рекурсії та к-сть ітерацій

void welcome()//------identification of developer-------
{
    cout << "Lab-5, task1, var-2\n";
    cout << "Developer: Byvalkevych Anastasia Victorivna, gr - 13" << endl;
    cout << "=====================================================" << endl;
    //content
    cout << "This program can help you calculate the number of combinations in two ways\n";
    cout << " k       n!\n";
    cout << "C =  ---------   we will use this formula\n";
    cout << " n    k!(n-k)!\n";
}
float Fact_recur(int x)  // факторіал рекурсією
{
    if (x == 0)
    {
        return 1;
        depth++;    // нарощення глибини рекурсії
    }
    else
    {
        depth++;
        return x * Fact_recur(x - 1);  // виклик функції самої себе
    }
}
float Fact_cycle(int number) // факторіал для цикла
{
    float fact = 1;
    if (number != 0)
    {
        for (int i = 1; i <= number; i++)
        {
            fact *= i;
            iterat++;
        }
    }
    return (float)fact;
}
int Comb_rec(int k, int n)
{
    if (k > n && n >= 0)
    {
        return 0;
    }
    if (k == n && n >= 0 || k == 0 && n > 0)
    {
        return 1;
    }
    else
    {
        return (Fact_recur(n - 1) / (Fact_recur(k - 1) * Fact_recur(n - k)) + Fact_recur(n - 1) / (Fact_recur(k) * Fact_recur(n - k - 1)));
    }
}
int Comb_cycle(int k, int n)
{
    if (k > n && n >= 0)
    {
        return 0;
    }
    if (k == n && n >= 0 || k == 0 && n > 0)
    {
        return 1;
    }
    else
    {
        return (Fact_cycle(n - 1) / (Fact_cycle(k - 1) * Fact_cycle(n - k)) + Fact_cycle(n - 1) / (Fact_cycle(k) * Fact_cycle(n - k - 1)));
    }
}
int main()
{
    welcome();
    bool answer = 0;
    do
    {
        cout << "If you are ready, enter your coefficients:\n";
        cout << "=====================================================" << endl;
        cout << "Your k = ";
        cin >> k;
        cout << "Your n = ";
        cin >> n;
        cout << "-----------------------------------------------------\n";
        cout << "Answer using recursion:\n";
        cout << " k\n";
        cout << "C = " << Comb_rec(k, n) <<endl;
        cout << " n\n";
        cout << "The depth of recursion - "<< depth << endl;
        cout << "-----------------------------------------------------\n";
        cout << "Answer using cycle:\n";
        cout << " k\n";
        cout << "C = " << Comb_cycle(k, n) << endl;
        cout << " n\n";
        cout << "The number of iterations - " << iterat << endl;
        cout << "-----------------------------------------------------\n";
        cout << "\nDo you want to try again? Yes=1, No=0\n";
        cin >> answer;
    } while (answer != 0);
    system("pause");
}