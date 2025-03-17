/*Envision creating a robust application for a global finance firm that needs to handle and compute multiple currencies 
with real-time conversion capabilities. This system is built on a base class called Currency, 
which contains core data members such as amount, currencyCode, currencySymbol, and an optional exchangeRate.
It provides functions like convertToBase() for converting the amount into a common base currency, convertTo(targetCurrency)

for converting between currencies, and displayCurrency() for showcasing currency details.

Derived classes like Dollar, Euro, and Rupee extend this foundation by introducing currency-specific details
and overriding convertToBase() and displayCurrency() to reflect the exchange rates and regional currency formats 
dynamically.*/


#include <iostream>
#include <string>
using namespace std;

class Currency {
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate;

public:
    Currency(double amt, string code, string symbol, double rate = 1.0)
        : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

    virtual double convertToBase() = 0;
    virtual double convertTo(Currency* targetCurrency) {
        double baseAmount = convertToBase();
        return baseAmount / targetCurrency->exchangeRate;
    }
    virtual void displayCurrency() = 0;
};

class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}

    double convertToBase() override {
        return amount;
    }

    void displayCurrency() override {
        cout << currencySymbol << amount << " (" << currencyCode << ")" << endl;
    }
};

class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", "€", 1.1) {}

    double convertToBase() override {
        return amount * exchangeRate;
    }

    void displayCurrency() override {
        cout << currencySymbol << amount << " (" << currencyCode << ")" << endl;
    }
};

class Rupee : public Currency {
public:
    Rupee(double amt) : Currency(amt, "INR", "₹", 0.012) {}

    double convertToBase() override {
        return amount * exchangeRate;
    }

    void displayCurrency() override {
        cout << currencySymbol << amount << " (" << currencyCode << ")" << endl;
    }
};

int main() {
    Dollar d(100);
    Euro e(100);
    Rupee r(100);

    d.displayCurrency();
    e.displayCurrency();
    r.displayCurrency();

    cout << "100 EUR to USD: " << e.convertTo(&d) << " USD" << endl;
    cout << "100 INR to USD: " << r.convertTo(&d) << " USD" << endl;

    return 0;
}
