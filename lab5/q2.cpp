/*Create a class called LoanHelper, which helps the user calculate their loan payments. The class
should have a variable that stores
--interest rate for the loan as a user defined constant value.
--the amount for the loan taken
--and amount of months that the user will repay the loan in.
The loan repayment should be calculated on a monthly basis, and the interest rate
should be applied over the monthly return amount. The output should be something like:
“You have to pay 999 every month for 12 monthsto repay your loan”
Note: first divide loan amount by number of months, then apply the interest rate on it. Interest rate
should be a value between 0-0.5%*/


not wokring #include <iostream>
using namespace std;

class LoanHelper {
    const float interestRate;
    float LoanAmount;
    int months;

public:
    LoanHelper(float LoanAmount, int months, float iR) : interestRate(iR) {
        this->LoanAmount = LoanAmount;
        this->months = months;
    }

    void calculateMonthlyPayment() {
        float totalRepayment = LoanAmount * (1 + interestRate * months); // Corrected formula
        float monthlyPayment = totalRepayment / months;
        cout << "You have to pay " << monthlyPayment << " every month for " << months 
             << " months to repay your loan." << endl;
    }
};

int main() {
    float amount, rate;
    int duration;

    cout << "Enter loan amount: ";
    cin >> amount;
    cout << "Enter repayment duration in months: ";
    cin >> duration;
    cout << "Enter interest rate (between 0% and 0.5% as decimal): ";
    cin >> rate;

    // Validation checks
    if (amount <= 0) {
        cout << "Error: Loan amount must be greater than 0." << endl;
        return 1;
    }
    if (duration <= 0) {
        cout << "Error: Repayment duration must be greater than 0 months." << endl;
        return 1;
    }
    if (rate < 0.0 || rate > 0.5) {
        cout << "Error: Interest rate should be between 0% and 0.5%." << endl;
        return 1;
    }

    LoanHelper loan(amount, duration, rate);
    loan.calculateMonthlyPayment();

    return 0;
}
