#include <iostream>
using namespace std;

float calc(float a, float b, int op)
{
    if (op == 1)
        return a + b;
    else if (op == 2)
        return a - b;
    else if (op == 3)
        return a * b;
    else if (op == 4)
    {
        if (b != 0)
            return a / b;
        else
        {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
    }
    else
    {
        cout << "Invalid operation!" << endl;
        return 0;
    }
}

int main()
{
    float num1, num2;
    int operation;

    cout << "This is a simple calculator." << endl;

    cout << "Enter first num: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "Enter operation you wish to perform." << endl;
    cout << "1/2/3/4 = Add/Subtract/Multiply/Divide: ";
    cin >> operation;

    float result = calc(num1, num2, operation);
    cout << "The answer is: " << result << endl;

    return 0;
}