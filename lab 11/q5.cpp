/*Create a template class BankAccount<T> where T is the currency type (e.g., double, int).
Throw an InsufficientFundsException (class) if a withdrawal exceeds the balance. Include the deficit amount in the exception message.

Requirements:
withdraw(T amount) throws the exception if amount > balance.

Catch the exception and display the deficit.*/


#include <iostream>
#include <exception>
#include <string>
using namespace std;

class InsufficientFundsException : public exception {
private:
    string message;
public:
    InsufficientFundsException(const string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

template <typename T>
class BankAccount {
private:
    T balance;
public:
    BankAccount(T initialBalance) : balance(initialBalance) {}

    T getBalance() const {
        return balance;
    }

    void withdraw(T amount) {
        if (amount > balance) {
            T deficit = amount - balance;
            throw InsufficientFundsException("Deficit: $" + to_string(deficit));
        }
        balance -= amount;
        cout << "Withdrew $" << amount << ". New balance: $" << balance << endl;
    }
};

int main() {
    try {
        BankAccount<double> account(500.00);
        cout << "Balance: $" << account.getBalance() << endl;

        account.withdraw(200.00);
        account.withdraw(600.00);
    }
    catch (const InsufficientFundsException& e) {
        cerr << "InsufficientFundsException - " << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
