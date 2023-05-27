// Four function calculator

#include <iostream>

int getUserInput(const std::string& prompt);
char getOperator();
void performCalculation(int num1, int num2, char op);

int main()
{
    char choice;
    do
    {
        int num1 = getUserInput("Enter the first number: ");
        char op = getOperator();
        int num2 = getUserInput("Enter the second number: ");

        performCalculation(num1, num2, op);

        std::cout << "Do you want to do another calculation? (Y/N): ";
        std::cin >> choice;
    } while (choice != 'N' && choice != 'n');

    return 0;
}

int getUserInput(const std::string& prompt)
{
    int num;
    std::cout << prompt;
    std::cin >> num;
    return num;
}

char getOperator()
{
    char op;
    std::cout << "Enter operator (+, -, *, /): ";
    std::cin >> op;
    return op;
}

void performCalculation(int num1, int num2, char op)
{
    switch (op)
    {
        case '+':
            std::cout << "Result: " << num1 + num2 << std::endl;
            break;
        case '-':
            std::cout << "Result: " << num1 - num2 << std::endl;
            break;
        case '*':
            std::cout << "Result: " << num1 * num2 << std::endl;
            break;
        case '/':
            if (num2 != 0)
                std::cout << "Result: " << num1 / num2 << std::endl;
            else
                std::cout << "[Error] Division by zero!" << std::endl;
            break;
        default:
            std::cout << "[Error] Invalid operator!" << std::endl;
    }
}
