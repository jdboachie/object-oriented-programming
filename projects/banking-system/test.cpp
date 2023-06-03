#include <iostream>
#include "models.cpp"

int main()
{
    BankAccount* account = new BankAccount("123456789", 1000, "John Doe");
    account->displayBalance();
    account->deposit(100);
    account->displayBalance();
    account->withdraw(200);
    account->displayBalance();
    account->withdraw(1000);
    account->displayBalance();

    SavingsAccount* savingsAccount = new SavingsAccount("987654321", 1000, "Jane Doe", 0.05);
    savingsAccount->displayBalance();
    savingsAccount->deposit(100);
    savingsAccount->displayBalance();
    savingsAccount->withdraw(200);
    savingsAccount->displayBalance();
    savingsAccount->withdraw(1000);
    savingsAccount->displayBalance();

    Bank *bank = new Bank();
    bank->addAccount(account);
    return 0;
}