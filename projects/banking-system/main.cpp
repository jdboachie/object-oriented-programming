#include <iostream>
#include "models.cpp"

int main()
{
    std::cout << "WELCOME TO DABANK" << std::endl;

    Bank *bank = new Bank();

    bank->createAccount();
    bank->displayAllAccounts();
    bank->performTransaction();

    return 0;
}