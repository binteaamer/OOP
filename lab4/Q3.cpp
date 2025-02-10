#include <iostream>
using namespace std;
class Account {
private:
   string accountNumber, accountHolderName;
   double balance;
public:
    Account() {
        accountNumber = "";
        accountHolderName = "";
        balance = 0.0;
    }
    Account(string anum, string ahold, double b) {
        balance = b;
        accountNumber = anum;
        accountHolderName = ahold;
    }
    string getAccountNum() {
        return accountNumber;
    }
    string getAccountHoldName() {
        return accountHolderName;
    }
   double getBalance() {
        return balance;
    }
    void deposit(double amount) {
      balance = balance + amount;
    }
    void withdraw (double amount) { if(amount > balance || amount < 0){
        cout << "invalid amount" << endl;
    }else
    balance = balance - amount;
    cout << "Withdrawing..." << endl;
    }
    void checkBalance() {
      cout << " Your current balance is : " << balance << endl;
    }
   
};

int main() {
    Account object("34K874CUDM0", "Abeeha Binte Aamer", 367890.34);
    cout << " Bank Account Number :  " << object.getAccountNum() << endl;
    cout << " Bank Account Holder Name  : " << object.getAccountHoldName() << endl;
    cout << " Current Balance : " << object.getBalance() << endl;
    object.deposit(9035.794);
    object.withdraw(2345.7);
    object.checkBalance();
}
