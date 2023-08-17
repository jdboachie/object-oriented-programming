#include <iostream>
#include <random>

using namespace std;

class BankAccount
{
private:
    double balance;

public:
    string name;
    string accountNumber;

    BankAccount(string accountNumber, double balance, string name)
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
            cout << "[ERROR] Insufficient funds" << endl;
        }
        else
        {
            balance -= amount;
        }
    }

    virtual void displayBalance()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : public BankAccount
{
private:
    double interestRate;

public:
    SavingsAccount(string accountNumber, double balance, string name, double interestRate) : BankAccount(accountNumber, balance, name)
    {
        this->interestRate = interestRate;
    }

    void displayBalance() override
    {
        BankAccount::displayBalance();
        cout << "[INFO] Interest Rate: " << interestRate << endl;
    }
};

class CheckingAccount : public BankAccount
{
private:
    double transactionLimit;

public:
    CheckingAccount(string accountNumber, double balance, string name) : BankAccount(accountNumber, balance, name)
    {
        this->transactionLimit = 10000;
    }

    void withdraw(double amount) override
    {
        if (amount > transactionLimit)
        {
            cout << "[ERROR] Transaction limit exceeded" << endl;
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
        string accountNumber;
        string name;
        double balance = 0;

        cout << "[PROMPT] Enter your name: ";
        getline(cin, name);
        cout << "[PROMPT] Enter initial deposit: ";
        cin >> balance;
        accountNumber = generateAccountNumber();

        // Create a new BankAccount object
        BankAccount *account = new BankAccount(accountNumber, balance, name);
        addAccount(account);
    }

    static string generateAccountNumber()
    {
        random_device rd;
        mt19937 generator(rd());
        uniform_int_distribution<int> distribution(10000000, 99999999);
        int randomNumber = distribution(generator);
        return "ACC" + to_string(randomNumber);
    }

    void displayAllAccounts()
    {
        cout << "[INFO] All accounts" << endl;
        for (int i = 0; i < population; i++)
        {
            accounts[i]->displayBalance();
        }
        cout << "[INFO] End of accounts" << endl;
    }

    bool findAccount(string accountNumber, bool verbose = false)
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
        string accountNumber;
        cout << "[PROMPT] Enter account number: ";
        cin >> accountNumber;

        if (!findAccount(accountNumber, true))
        {
            cout << "[ERROR] Account not found" << endl;
            return;
        }

        string transactionType;
        cout << "[PROMPT] Enter transaction. Type (deposit/withdraw): ";
        cin >> transactionType;

        double amount;
        cout << "[PROMPT] Enter amount: ";
        cin >> amount;

        for (int i = 0; i < population; i++)
        {
            if (accounts[i]->accountNumber == accountNumber)
            {
                if (transactionType == "deposit")
                {
                    accounts[i]->deposit(amount);
                    cout << "[INFO] Deposited " << amount << " to " << accounts[i]->accountNumber << endl;
                }
                else if (transactionType == "withdraw")
                {
                    accounts[i]->withdraw(amount);
                    cout << "[INFO] Withdrew " << amount << " from " << accounts[i]->accountNumber << endl;
                }
            }
        }
    }
};
