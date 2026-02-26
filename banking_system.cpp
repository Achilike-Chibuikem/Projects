#include <iostream>
#include <string>
using namespace std;

class Account
{
public:
    string name;
    double balance;

    Account(string n, double b)
    {
        name = n;
        balance = b;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited $" << amount << ". New balance: $" << balance << "\n";
    }

    void withdraw(double amount)
    {
        if (amount > balance)
            cout << "Insufficient funds!\n";
        else
        {
            balance -= amount;
            cout << "Withdrew $" << amount << ". New balance: $" << balance << "\n";
        }
    }

    void display()
    {
        cout << "Account holder: " << name << "\nBalance: $" << balance << "\n";
    }
};

int main()
{
    string name;
    double initialBalance;

    cout << "Enter account holder name: ";
    getline(cin, name);

    cout << "Enter initial balance: ";
    cin >> initialBalance;

    Account acc(name, initialBalance);

    int choice;
    double amount;

    do
    {
        cout << "\n===== BANK MENU =====\n";
        cout << "1. Display Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            acc.display();
            break;

        case 2:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            acc.deposit(amount);
            break;

        case 3:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            acc.withdraw(amount);
            break;

        case 0:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid option. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
