#include<iostream>
#include<string>
using namespace std;

 class currency{
    protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate;

    public:
    currency():amount(0.0),currencyCode(""),currencySymbol(""),exchangeRate(0.0) {}
    currency(double amt, string code, string symbol, double rate):amount(amt),currencyCode(code), currencySymbol(symbol),exchangeRate(rate){}
  
   virtual double convertToBase()=0;
   virtual void displayCurrency()=0;

   virtual double convertTo(currency *targetCurrency){
    double baseamount= convertToBase();
    return baseamount / targetCurrency->exchangeRate;}

 };

 class dollar: public currency{
    public:
    dollar(double amt):currency(amt,"USD","$", 1.0){}
    double convertToBase() override {
        return amount;
    }

    void displayCurrency() override {
        cout << currencySymbol << amount << " (" << currencyCode << ")" << endl;
    }

 };


 class euro: public currency{
    public:
    euro(double amt):currency(amt,"EUR","€", 1.1){}
    double convertToBase()override{
        return amount*exchangeRate;
    }

    void displayCurrency() override {
        cout << currencySymbol << amount << " (" << currencyCode << ")" << endl;
    }

    
 };
 class rupee: public currency{
    public:

    rupee(double amt):currency(amt,"INR","₹",0.012){}
    double convertToBase()override{
        return amount*exchangeRate;
    }
    void displayCurrency() override {
        cout << currencySymbol << amount << " (" << currencyCode << ")" << endl;
    }


 };





int main(){ 
    dollar d(1000);
    d.displayCurrency();
    euro e(100);
    rupee r(500);

    e.displayCurrency();
    cout << "100 EUR to USD: " << e.convertTo(&d) << " USD" << endl;
    cout << "100 INR to USD: " << r.convertTo(&d) << " USD" << endl;



return 0;

 }
 
