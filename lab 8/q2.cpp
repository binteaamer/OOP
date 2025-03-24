#include <iostream> // commments are for my own understanding later 
#include <string>
using namespace std;

class Account {
private:
    string accountNumber;
    string accountHolder;
    double balance;

public:
    // Constructor
    Account(string accNum, string holder, double initialBalance)
        : accountNumber(accNum), accountHolder(holder), balance(initialBalance) {}

    // Operator overloading for adding balances of two accounts (+)
    Account operator+(const Account &other) {
        double combinedBalance = this->balance + other.balance;
        return Account("TEMP", "Combined", combinedBalance); // Temporary account for result
    }

    // Operator overloading for transferring amount (=)
    Account& operator=(double amount) {
        this->balance = amount; // Direct assignment (simplified transfer)
        return *this;
    }

    // Operator overloading for comparing balances (>)
    bool operator>(const Account &other) {
        return this->balance > other.balance;
    }

    // Friend function for displaying account details (<<)
    friend ostream& operator<<(ostream &os, const Account &acc) {
        os << "Account Number: " << acc.accountNumber << "\n"
           << "Account Holder: " << acc.accountHolder << "\n"
           << "Balance: $" << acc.balance << "\n";
        return os;
    }

    // Helper function to transfer funds between accounts
    void transferTo(Account &recipient, double amount) {
        if (this->balance >= amount) {
            this->balance -= amount;
            recipient.balance += amount;
            cout << "Transferred $" << amount << " to " << recipient.accountHolder << "\n";
        } else {
            cout << "Insufficient balance for transfer!\n";
        }
    }

    // Getters
    string getAccountNumber() const { return accountNumber; }
    string getAccountHolder() const { return accountHolder; }
    double getBalance() const { return balance; }
};

int main() {
    // Create accounts
    Account acc1("ACC123", "Alice", 1000.0);
    Account acc2("ACC456", "Bob", 500.0);

    // Display initial account details
    cout << "--- Initial Balances ---\n";
    cout << acc1 << acc2;

    // 1. Add balances of two accounts (+ operator)
    Account combined = acc1 + acc2;
    cout << "\n--- Combined Balance ---\n";
    cout << "Total: $" << combined.getBalance() << "\n";

    // 2. Transfer amount using helper (simulates = operator)
    acc1.transferTo(acc2, 200.0);
    cout << "\n--- After Transfer ---\n";
    cout << acc1 << acc2;

    // 3. Compare balances (> operator)
    cout << "\n--- Balance Comparison ---\n";
    if (acc1 > acc2) {
        cout << acc1.getAccountHolder() << " has a higher balance.\n";
    } else {
        cout << acc2.getAccountHolder() << " has a higher balance.\n";
    }

    // 4. Display details using << operator (already demonstrated above)
    return 0;
}
