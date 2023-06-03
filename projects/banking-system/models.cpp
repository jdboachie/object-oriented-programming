#include <iostream>

class BankAccount
{
    private:
        double balance;
    
    public:
        std::string name;
        std::string accountNumber;
        
        BankAccount(std::string accountNumber, double balance, std::string name)
        {
            this->accountNumber = accountNumber;
            this->balance = balance;
            this->name = name;
        }
        
        void deposit(double amount)
        {
            balance += amount;
        }

        virtual void withdraw(double amount)
        {
            if (balance - amount < 0)
            {
                std::cout << "Insufficient funds" << std::endl;
            }
            else
            {
                balance -= amount;
            }
        }

        virtual void displayBalance()
        {
            std::cout << "Account Number: " << accountNumber << std::endl;
            std::cout << "Balance: " << balance << std::endl;
        }
};

class SavingsAccount: public BankAccount
{
    private:
        double interestRate;
    
    public:
        SavingsAccount(std::string accountNumber, double balance, std::string name, double interestRate): BankAccount(accountNumber, balance, name)
        {
            this->interestRate = interestRate;
        }

        void displayBalance() override
        {
            std::cout << "Interest Rate: " << interestRate << std::endl;
        }

};

class CheckingAccount: public BankAccount
{
    private:
        double transactionLimit;
    
    public:
        CheckingAccount(std::string accountNumber, double balance, std::string name): BankAccount(accountNumber, balance, name)
        {
            this->transactionLimit = 10000;
        }

        void withdraw (double amount) override
        {
            if (amount > transactionLimit)
            {
                std::cout << "Transaction limit exceeded" << std::endl;
            }
            else
            {
                BankAccount::withdraw(amount);
            }
        };

};

class Bank
{
    private:
        BankAccount** accounts;
    
    public:
        Bank()
        {
            accounts = new BankAccount*[10];
        }

        void addAccount(BankAccount* account)
        {
            for (int i = 0; i < sizeof(accounts); i++)
            {
                if (accounts[i] == NULL)
                {
                    accounts[i] = account;
                    break;
                }
            }
        }

        void createAccount()
        {
            std::string accountNumber;
            std::string name;
            double balance = 0;

            std::cout << "Enter your name: ";
            std::cin >> name;
            std::cout << "Enter account number: ";
            std::cin >> accountNumber;

            // Create a new BankAccount object
            BankAccount* account = new BankAccount(accountNumber, balance, name);
        }

        void displayAllAccounts()
        {
            for (int i = 0; i < sizeof(accounts); i++)
            {
                accounts[i]->displayBalance();
            }
        }

        void findAccount(std::string accountNumber)
        {
            for (int i = 0; i < sizeof(accounts); i++)
            {
                if (accounts[i]->accountNumber == accountNumber)
                {
                    accounts[i]->displayBalance();
                }
            }
        }

        void performTransaction()
        {
            std::string accountNumber;
            std::cout << "Enter account number: ";
            std::cin >> accountNumber;

            std::string transactionType;
            std::cout << "Enter transaction. Type (deposit/withdraw): ";
            std::cin >> transactionType;

            double amount;
            std::cout << "Enter amount: ";
            std::cin >> amount;

            for (int i = 0; i < sizeof(accounts); i++)
            {
                if (accounts[i]->accountNumber == accountNumber)
                {
                    if (transactionType == "deposit")
                    {
                        accounts[i]->deposit(amount);
                    }
                    else if (transactionType == "withdraw")
                    {
                        accounts[i]->withdraw(amount);
                    }
                }
            }
        }
};
