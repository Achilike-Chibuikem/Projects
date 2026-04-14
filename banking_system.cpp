#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Account
{
protected:
    string name;
    double balance;

public:
    Account(string n, double b) : name(n), balance(b) {}

    void deposit(double amount)
    {
        if (amount < 1)
        {
            cout << "Deposit cannot be less than $1!" << endl;
        }
        else
        {
            balance += amount;
            cout << "Deposited $" << amount << ". New balance: $" << balance << "." << endl;
        }
    }

    void withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient funds!" << endl;
        }
        else
        {
            balance -= amount;
            cout << "Withdrew $" << amount << ". New balance: $" << balance << "." << endl;
        }
    }

    void display()
    {
        cout << "Account holder: " << name << " | Balance: $" << balance << "." << endl;
    }
};

class SavingsAccount : public Account
{
public:
    SavingsAccount(string n, double b) : Account(n, b) {}

    void withdraw(double amount)
    {
        const double MIN_BALANCE = 100;
        if (amount > balance - MIN_BALANCE)
        {
            cout << "Withdrawal denied! Minimum balance requirement ($" << MIN_BALANCE << ")." << endl;
        }
        else
        {
            balance -= amount;
            cout << "Withdrew $" << amount << ". New balance: $" << balance << "." << endl;
        }
    }

    void compound_interest()
    {
        float rate = 0.05;
        double freq = 12;
        double time;
        cout << "Enter years (decimal) for interest calculation: ";
        cin >> time;
        double final_amount = balance * pow(1 + (rate / freq), freq * time);
        cout << "Future balance after " << time << " years: $" << final_amount << "." << endl;
    }

    void savings_menu()
    {
        int choice;
        double amount;

        do
        {
            cout << "\n===== SAVINGS ACCOUNT MENU =====" << endl;
            cout << "1. Display Balance" << endl;
            cout << "2. Deposit" << endl;
            cout << "3. Withdraw" << endl;
            cout << "4. Calculate Compound Interest" << endl;
            cout << "0. Return to Main Menu" << endl;
            cout << "Choose an option: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                display();
                break;
            case 2:
                cout << "Enter deposit amount: $";
                cin >> amount;
                deposit(amount);
                break;
            case 3:
                cout << "Enter withdrawal amount: $";
                cin >> amount;
                withdraw(amount);
                break;
            case 4:
                compound_interest();
                break;
            case 0:
                cout << "Returning to main menu..." << endl;
                break;
            default:
                cout << "Invalid option!" << endl;
            }
        } while (choice != 0);
    }
};

class CurrentAccount : public Account
{
public:
    CurrentAccount(string n, double b) : Account(n, b) {}

    void withdraw(double amount)
    {
        const double OVERDRAFT_LIMIT = -1000;
        if (balance - amount < OVERDRAFT_LIMIT)
        {
            cout << "Withdrawal denied! Overdraft limit exceeded." << endl;
        }
        else
        {
            balance -= amount;
            cout << "Withdrew $" << amount << ". New balance: $" << balance << "." << endl;
        }
    }

    void current_menu()
    {
        int choice;
        double amount;

        do
        {
            cout << "\n===== CURRENT ACCOUNT MENU =====" << endl;
            cout << "1. Display Balance" << endl;
            cout << "2. Deposit" << endl;
            cout << "3. Withdraw" << endl;
            cout << "0. Return to Main Menu" << endl;
            cout << "Choose an option: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                display();
                break;
            case 2:
                cout << "Enter deposit amount: $";
                cin >> amount;
                deposit(amount);
                break;
            case 3:
                cout << "Enter withdrawal amount: $";
                cin >> amount;
                withdraw(amount);
                break;
            case 0:
                cout << "Returning to main menu..." << endl;
                break;
            default:
                cout << "Invalid option!" << endl;
            }
        } while (choice != 0);
    }
};

int main()
{
    string name;
    double savingsBalance, currentBalance;

    cout << "Enter account holder name: ";
    getline(cin, name);

    char openSavings;
    cout << "Do you wish to open a Savings Account? (y/n): ";
    cin >> openSavings;

    if (openSavings == 'y' || openSavings == 'Y')
    {
        cout << "Enter initial balance for Savings Account: $";
        cin >> savingsBalance;
    }
    else
    {
        savingsBalance = 0;
        cout << "Savings Account not opened." << endl;
    }

    cout << "Enter initial balance for Current Account: $";
    cin >> currentBalance;

    SavingsAccount savings_acc(name, savingsBalance);
    CurrentAccount current_acc(name, currentBalance);

    int choice;

    do
    {
        cout << "\n===== MAIN MENU =====" << endl;
        cout << "1. Savings Account" << endl;
        cout << "2. Current Account" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (openSavings == 'y' || openSavings == 'Y')
                savings_acc.savings_menu();
            else
                cout << "You do not have a Savings Account." << endl;
            break;
        case 2:
            current_acc.current_menu();
            break;
        case 0:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid option!" << endl;
        }
    } while (choice != 0);

    return 0;
}