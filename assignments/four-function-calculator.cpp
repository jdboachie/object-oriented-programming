// Four-function Calculator

#include <iostream>

using namespace std;

int main()
{
    int num1, num2;
    char op;

    cout << "Enter first number: " << endl;
    cin >> num1;

    cout << "Enter operator: " << endl;
    cin >> op;

    cout << "Enter second number: " << endl;
    cin >> num2;

    switch (op)
    {
        case '+':
            cout << num1 + num2 << endl;
            break;
        case '-':
            cout << num1 - num2 << endl;
            break;
        case '*':
            cout << num1 * num2 << endl;
            break;
        case '/':
            cout << num1 / num2 << endl;
            break;
        default:
            cout << "Invalid operator" << endl;
            break;
    }
    
    return 0; // Success
}
