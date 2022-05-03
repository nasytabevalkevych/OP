/*Увести з клавіатури два цілих числа A і В.
Використовуючи рекурсію, вивести всі числа від A до В включно в порядку зростання,
якщо A більше В або в порядку спадання в іншому випадку. 
*/
#include<iostream>
#include<math.h>
using namespace std;
int a, b;
int order(int a, int b)
{
    if (a == b)
    {
        return a = b;
    }
    if (a < b)
    {
        cout << a << endl;
        a++;
        return order(a, b);
    }
    else
    {
        cout << a << endl;
        a--;
        return order(a, b);
    }
}
void welcome()//------identification of developer-------
{
    cout << "Lab-5, task2, var-2\n";
    cout << "Developer: Byvalkevych Anastasia Victorivna, gr - 13" << endl;
    cout << "=====================================================" << endl;
    //content
    cout << "This program can help you display all numbers in ascending or descending order\n";
}
int main()
{
    welcome();
    bool answer = 0;
    do
    {
        cout << "If you are ready, enter your numbers:\n";
        cout << "=====================================================" << endl;
        cout << "Your A = ";
        cin >> a;
        cout << "Your B = ";
        cin >> b;
        cout << order(a, b) << endl;
        cout << "\nDo you want to try again? Yes=1, No=0\n";
        cin >> answer;
    } while (answer != 0);
    system("pause");
}