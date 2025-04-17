/*Problem: An e-commerce platform aims to support multiple payment methods (credit
cards, digital wallets) to attract global customers. The payment system must validate
transactions securely and allow new payment options (e.g., cryptocurrency) to be added
without rewriting existing code.
Classes and Structure:
• Abstract Class PaymentMethod:
o Member Function:
▪ processPayment(double amount): Pure virtual function to handle
transactions.
• Derived Class CreditCard:
o Data Members:
▪ cardNumber (string): Stores the card number.
o Implements processPayment() to validate and process payments.
• Derived Class DigitalWallet:
o Data Members:
▪ balance (double): Tracks available funds.
o Implements processPayment() to deduct balance.

Flow:
• Create CreditCard and DigitalWallet objects.
• Simulate payments and check for success/failure.*/  



#include <iostream>
using namespace std;

class PaymentMethod {
public:
    virtual void processPayment(double amount) = 0; 
    virtual ~PaymentMethod() {} 
};

class CreditCard : public PaymentMethod {
    string cardNumber;

public:
    CreditCard(string cnum) : cardNumber(cnum) {}

    void processPayment(double amount) override {
        if (amount <= 0) {
            cout << "Invalid amount entered for credit card transaction." << endl;
        } else {
            cout << "Credit card " << cardNumber << " charged $" << amount << " successfully." << endl;
        }
    }
};

class DigitalWallet : public PaymentMethod {
    double balance;

public:
    DigitalWallet(double b) : balance(b) {}

    void processPayment(double amount) override {
        if (amount <= 0) {
            cout << "Invalid payment amount for digital wallet." << endl;
        } else if (amount > balance) {
            cout << "Payment failed: Insufficient balance. Available: $" << balance << ", Required: $" << amount << endl;
        } else {
            balance -= amount;
            cout << "Digital Wallet payment of $" << amount << " successful. Remaining balance: $" << balance << endl;
        }
    }
};

int main() {-
  
    PaymentMethod* p1 = new CreditCard("1234-5678-9012-3456");
    PaymentMethod* p2 = new DigitalWallet(100.0);

    p1->processPayment(50.0);
    p2->processPayment(30.0);
    p2->processPayment(80.0);  
    delete p1;
    delete p2;

    return 0;
}
