/*Imagine developing a comprehensive banking system simulator for a prominent financial institution. In this system,
a base class called Account encapsulates essential data members such as accountNumber, balance, accountHolderName, and optionally accountType.
It offers member functions like deposit(amount) to add funds, withdraw(amount) to remove funds with proper error checking, calculateInterest()
to compute interest based on varying rules, printStatement() to output detailed transaction histories, and getAccountInfo() 
to retrieve general account details.
Derived classes like SavingsAccount, CheckingAccount, and FixedDepositAccount extend this structure by incorporating specialized data members—such as
interestRate and minimumBalance for SavingsAccount or maturityDate and fixedInterestRate for FixedDepositAccount.
These derived classes override key functions like calculateInterest() and printStatement() to provide account-type-specific functionalities. Additionally,
the withdraw() function is overridden in specific accounts to apply different transaction rules,
ensuring that each account type follows realistic banking policies while maintaining polymorphic behavior.*/

#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    int accountNumber;
    double balance;
    string accountHolderName;
    string accountType;
public:
    Account() : accountNumber(0), balance(0.0), accountHolderName("Unknown"), accountType("Default") {}

    Account(int accNum, double bal, string holderName, string type = "Default") 
        : accountNumber(accNum), balance(bal), accountHolderName(holderName), accountType(type) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << " into account " << accountNumber << ".\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    virtual void withdraw(double amount) = 0;  // Pure virtual function (declared in base, defined in derived )
    virtual double calculateInterest() = 0;   // Pure virtual function
    virtual void printStatement() = 0;        // Pure virtual function

    void getAccountInfo() {
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Account Holder: " << accountHolderName << "\n";
        cout << "Balance: $" << balance << "\n";
        cout << "Account Type: " << accountType << "\n";
    }
};

class SavingsAccount : public Account {
    double interestRate;
    double minimumBalance;
public:
    SavingsAccount() : interestRate(0.03), minimumBalance(1000) {}  // Default constructor

    SavingsAccount(int accNum, double bal, string holderName, double rate, double minBal)
        : Account(accNum, bal, holderName, "Savings"), interestRate(rate), minimumBalance(minBal) {}

    void withdraw(double amount) override {
        if ((balance - amount) < minimumBalance) {
            cout << "Withdrawal denied! Must maintain a minimum balance of $" << minimumBalance << ".\n";
        } else {
            balance -= amount;
            cout << "Withdrawn $" << amount << " from Savings Account.\n";
        }
    }

    double calculateInterest() override {
        return balance * interestRate;
    }

    void printStatement() override {
        cout << "Savings Account Statement for " << accountHolderName << ":\n";
        cout << "Balance: $" << balance << "\n";
        cout << "Interest Earned: $" << calculateInterest() << "\n";
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(int accNum, double bal, string holderName)
        : Account(accNum, bal, holderName, "Checking") {}

    void withdraw(double amount) override {
        if (amount > balance) {
            cout << "Insufficient funds in Checking Account.\n";
        } else {
            balance -= amount;
            cout << "Withdrawn $" << amount << " from Checking Account.\n";
        }
    }

    double calculateInterest() override {
        return 0;  // No interest for checking accounts
    }

    void printStatement() override {
        cout << "Checking Account Statement for " << accountHolderName << ":\n";
        cout << "Balance: $" << balance << "\n";
    }
};

class FixedDepositAccount : public Account {
    string maturityDate;
    double fixedInterestRate;
public:
    string dateToday;

    FixedDepositAccount(int accNum, double bal, string holderName, string mDate, double rate)
        : Account(accNum, bal, holderName, "Fixed Deposit"), maturityDate(mDate), fixedInterestRate(rate) {
        cout << "Enter today's date (YYYY-MM-DD): ";
        cin >> dateToday;
    }

    void withdraw(double amount) override {
        if (dateToday == maturityDate) {
            balance -= amount;
            cout << "Withdrawn $" << amount << " from Fixed Deposit Account.\n";
        } else {
            cout << "Withdrawal not allowed before maturity date: " << maturityDate << ".\n";
        }
    }

    double calculateInterest() override {
        return balance * fixedInterestRate;
    }

    void printStatement() override {
        cout << "Fixed Deposit Account Statement for " << accountHolderName << ":\n";
        cout << "Balance: $" << balance << "\n";
        cout << "Maturity Date: " << maturityDate << "\n";
        cout << "Interest Earned: $" << calculateInterest() << "\n";
    }
};

int main() {
    // Early Binding Example
    cout << "\n--- Early Binding Example ---\n";
    Account *a;
    SavingsAccount sa1(201, 5000, "John Doe", 0.02, 1000);  // Initialized properly
    a = &sa1;
    a->withdraw(4500);  // Will use the SavingsAccount withdraw method

    // Creating different types of accounts
    cout << "\n--- Account Transactions ---\n";
    SavingsAccount sa(101, 5000, "Alice", 0.03, 1000);
    CheckingAccount ca(102, 2000, "Bob");
    FixedDepositAccount fda(103, 10000, "Charlie", "2026-12-31", 0.05);

    // Transactions
    sa.deposit(1000);
    sa.withdraw(4500);
    sa.printStatement();

    ca.withdraw(2500);
    ca.printStatement();

    fda.withdraw(500);
    fda.printStatement();

    return 0;
}
