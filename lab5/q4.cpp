/*Create a BankAccount class. Which contains following details and functionalties:
Attributes: The BankAccount class has three private member variables: accountNumber,
accountHolderName, and balance.
Create Constructor: The class has a constructor that takes parameters to initialize the account
details (accountNumber, accountHolderName, and balance).

Create following Member Functions:
• deposit(double amount): Adds the specified amount to the account balance.
• withdraw(double amount): Subtracts the specified amount from the account balance, if
sufficient funds are available.
• display(): Displays the account details including the account number, account holder name,
and balance.

In the main() function, create an array accounts of BankAccount objects. The array contains three
elements, each representing a different bank account.
Initialize Each BankAccount object with specific account details such as account number, holder
name, and initial balance.
Perform following operations:
• Iterate through each account in the accounts array.
• For each account, display the account details using the display() function.
• Perform Two Transactions:
• Deposits 500.0 rupees into the account.
• Withdraws 200.0 rupees from the account.
• After each transaction, display the updated account details, including the new balance.#includ*/

#include<iostream>
using namespace std;

class BankAccount{

string accountNumber, accountHolderName;
float balance;
public:
static float accountBalance;

BankAccount(string accNum, string accName, float bal): accountNumber(accNum), accountHolderName(accName), balance(bal)
{}
void  deposit(double amount){
accountBalance +=amount;
}
void withdraw(double amount){
if(accountBalance>amount){
    accountBalance-=amount;
}
else{
    cout<<"balance insufficient"<<endl;
    exit(1);

}
}
void display(){
cout<<"account number: "<<accountNumber<<endl;
cout<<"account name: "<<accountHolderName<<endl;
cout<<"balance: "<<accountBalance<<endl;

}

};

float BankAccount :: accountBalance= 0.0;
int main(){
    BankAccount accounts[3]{{"20240940", "abeeha binte aamer", 1200.00},
    {"20240644","laiba khan", 1700.0 },{"20240695","aamna rizwan", 2000.0}};

    for (int i=0; i <3; i++){
        cout << "\nInitial Details of Account " << i + 1 << ":" << endl;
        accounts[i].display();

        accounts[i].deposit(500.0);
        cout<<"\nafter deposit off 500"<<endl;
        accounts[i].display();
        accounts[i].withdraw(200.0);
        cout << "\nAfter withdrawing 200.0:" << endl;
        accounts[i].display();

    }
    return 0;
    
}
