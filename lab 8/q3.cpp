q1 
Yes, a friend function can overload the += operator because it has access to the private members of the class and can directly modify the left-hand operand.

Implementation Steps:
Declare the friend function inside the class.

Define the function to take the left-hand operand by non-const reference (to modify it) and the right-hand operand by const reference (to avoid unnecessary copies).

Modify the left-hand operand directly (since it’s a friend).

supporting code :*/

#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    // Friend declaration for operator+=
    friend BankAccount& operator+=(BankAccount& lhs, const BankAccount& rhs);

    void display() const {
        cout << "Balance: $" << balance << endl;
    }
};

// Friend function definition
BankAccount& operator+=(BankAccount& lhs, const BankAccount& rhs) {
    lhs.balance += rhs.balance;  // Directly modify private 'balance'
    return lhs;  // Return reference for chaining (e.g., a += b += c)
}

int main() {
    BankAccount acc1(1000.0), acc2(500.0);
    
    cout << "Before += operation:" << endl;
    acc1.display();  // Balance: $1000
    acc2.display();  // Balance: $500

    acc1 += acc2;    // Equivalent to: operator+=(acc1, acc2)

    cout << "\nAfter += operation:" << endl;
    acc1.display();  // Balance: $1500 (modified)
    acc2.display();  // Balance: $500 (unchanged)

    return 0;
}


q2
/*Yes, a friend function can be used to overload an operator where one operand is a primitive type, but with specific constraints.
Can a friend function handle this case?
Yes, but only when the class object is the first operand (e.g., object + int).
For int + object, a friend function cannot be used directly (explained below).

 How to implement it?
 Case1  object + int (Supported by Friend)
 case 2 Case: int + object (Not Supported by Friend)
*/

case 1 
#include <iostream>
using namespace std;

class Weight {
private:
    int kg;
public:
    Weight(int k) : kg(k) {}
    
    // Friend function for Weight + int
    friend Weight operator+(const Weight& w, int extraKg);
    
    void show() const { cout << "Weight: " << kg << " kg" << endl; }
};

// Friend definition
Weight operator+(const Weight& w, int extraKg) {
    return Weight(w.kg + extraKg);  // Direct private access
}

int main() {
    Weight w1(50);
    Weight w2 = w1 + 10;  // Works: object + int
    w2.show();            // Output: Weight: 60 kg
}
case 2
// Non-friend function for int + Weight
Weight operator+(int extraKg, const Weight& w) {
    return Weight(extraKg + w.getKg());  // Requires getter
}

// Add to Weight class:
public:
    int getKg() const { return kg; }  // Public getter



q3 
/*No, a friend function must use an object to access non-static private/protected members. It cannot access them directly (like static members) because friendship grants access only through instances of the class.

1. Does it always need an object?
Yes, for non-static members.

2. Can it access directly without an object?
No, unless the members are static.

3. When might it fail?
If no object is provided.

If the member is non-static and the function tries to access it without an object.*/

implentation:
class Safe {
private:
    static string code;  // Static private member

public:
    // Friend function declaration
    friend void crackCode();
};

// Static member initialization
string Safe::code = "1234";

// Friend function definition
void crackCode() {
    cout << "Cracked code: " << Safe::code << endl;  // Direct access (no object needed)
}

int main() {
    crackCode();  // Output: Cracked code: 1234
    return 0;
}
