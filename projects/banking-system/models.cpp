#include <iostream>
#include <random>

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
            std::cout << "[ERROR] Insufficient funds" << std::endl;
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

class SavingsAccount : public BankAccount
{
private:
    double interestRate;

public:
    SavingsAccount(std::string accountNumber, double balance, std::string name, double interestRate) : BankAccount(accountNumber, balance, name)
    {
        this->interestRate = interestRate;
    }

    void displayBalance() override
    {
        BankAccount::displayBalance();
        std::cout << "[INFO] Interest Rate: " << interestRate << std::endl;
    }
};

class CheckingAccount : public BankAccount
{
private:
    double transactionLimit;

public:
    CheckingAccount(std::string accountNumber, double balance, std::string name) : BankAccount(accountNumber, balance, name)
    {
        this->transactionLimit = 10000;
    }

    void withdraw(double amount) override
    {
        if (amount > transactionLimit)
        {
            std::cout << "[ERROR] Transaction limit exceeded" << std::endl;
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
    BankAccount **accounts;
    int population = 0;

public:
    Bank()
    {
        accounts = new BankAccount *[10];
    }

    void addAccount(BankAccount *account)
    {
        population++;
        for (int i = 0; i < population; i++)
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

        std::cout << "[PROMPT] Enter your name: ";
        std::getline(std::cin, name);
        std::cout << "[PROMPT] Enter initial deposit: ";
        std::cin >> balance;
        accountNumber = generateAccountNumber();

        // Create a new BankAccount object
        BankAccount *account = new BankAccount(accountNumber, balance, name);
        addAccount(account);
    }

    static std::string generateAccountNumber()
    {
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<int> distribution(10000000, 99999999);
        int randomNumber = distribution(generator);
        return "ACC" + std::to_string(randomNumber);
    }

    void displayAllAccounts()
    {
        std::cout << "[INFO] All accounts" << std::endl;
        for (int i = 0; i < population; i++)
        {
            accounts[i]->displayBalance();
        }
        std::cout << "[INFO] End of accounts" << std::endl;
    }

    bool findAccount(std::string accountNumber, bool verbose = false)
    {
        for (int i = 0; i < population; i++)
        {
            if (accounts[i]->accountNumber == accountNumber)
            {
                if (verbose)
                {
                    accounts[i]->displayBalance();
                }
                return true;
            }
        }
        return false;
    }

    void performTransaction()
    {
        std::string accountNumber;
        std::cout << "[PROMPT] Enter account number: ";
        std::cin >> accountNumber;

        if (!findAccount(accountNumber, true))
        {
            std::cout << "[ERROR] Account not found" << std::endl;
            return;
        }

        std::string transactionType;
        std::cout << "[PROMPT] Enter transaction. Type (deposit/withdraw): ";
        std::cin >> transactionType;

        double amount;
        std::cout << "[PROMPT] Enter amount: ";
        std::cin >> amount;

        for (int i = 0; i < population; i++)
        {
            if (accounts[i]->accountNumber == accountNumber)
            {
                if (transactionType == "deposit")
                {
                    accounts[i]->deposit(amount);
                    std::cout << "[INFO] Deposited " << amount << " to " << accounts[i]->accountNumber << std::endl;
                }
                else if (transactionType == "withdraw")
                {
                    accounts[i]->withdraw(amount);
                    std::cout << "[INFO] Withdrew " << amount << " from " << accounts[i]->accountNumber << std::endl;
                }
            }
        }
    }
};
