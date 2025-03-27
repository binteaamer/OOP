#include <iostream>
using namespace std;

class BankAccount {
protected:
    string accountNumber;
    double balance;

public:
    BankAccount(string accNum, double bal) : accountNumber(accNum), balance(bal) {}
    virtual void calculateInterest() = 0; // Pure virtual function
    
    // Deposit method overloading
    void deposit(double amount) {
        balance += amount;
        cout << "Deposited cash: $" << amount << "\n";
    }

    void deposit(double amount, string method) {
        balance += amount;
        cout << "Deposited $" << amount << " via " << method << "\n";
    }

    virtual void withdraw(double amount) = 0; // Pure virtual function
    
    // Operator Overloading
    BankAccount operator+(const BankAccount &acc) {
        return BankAccount(accountNumber, balance + acc.balance);
    }

    BankAccount operator-(double amount) {
        return BankAccount(accountNumber, balance - amount);
    }

    BankAccount operator*(double interestRate) {
        return BankAccount(accountNumber, balance * (1 + interestRate / 100));
    }

    BankAccount operator/(int installments) {
        return BankAccount(accountNumber, balance / installments);
    }
    
    void displayBalance() {
        cout << "Account: " << accountNumber << " Balance: $" << balance << "\n";
    }
};

class SavingsAccount : public BankAccount {
public:
    SavingsAccount(string accNum, double bal) : BankAccount(accNum, bal) {}
    
    void calculateInterest() override {
        balance *= 1.05; // 5% interest
    }

    void withdraw(double amount) override {
        if (balance - amount < 500) {
            cout << "Insufficient balance. Minimum $500 required.\n";
        } else {
            balance -= amount;
            cout << "Withdrawn: $" << amount << "\n";
        }
    }
};

class CurrentAccount : public BankAccount {
public:
    CurrentAccount(string accNum, double bal) : BankAccount(accNum, bal) {}
    
    void calculateInterest() override {
        cout << "No interest for Current Account.\n";
    }

    void withdraw(double amount) override {
        if (balance - amount < -1000) {
            cout << "Overdraft limit exceeded!\n";
        } else {
            balance -= amount;
            cout << "Withdrawn: $" << amount << "\n";
        }
    }
};

int main() {
    SavingsAccount savings("S123", 1000);
    CurrentAccount current("C456", 500);
    
    // Deposit Overloading
    savings.deposit(200);
    current.deposit(300, "Check");
    
    // Withdraw Overriding
    savings.withdraw(600);
    current.withdraw(1400);
    
    // Operator Overloading Demonstration
    savings.calculateInterest();
    savings.displayBalance();
    
    current.calculateInterest();
    current.displayBalance();
    
    BankAccount totalBalance = savings + current;
    totalBalance.displayBalance();
    
    BankAccount deductedBalance = savings - 100;
    deductedBalance.displayBalance();
    
    BankAccount appliedInterest = savings * 5;
    appliedInterest.displayBalance();
    
    BankAccount installment = savings / 3;
    installment.displayBalance();
    
    return 0;
}
