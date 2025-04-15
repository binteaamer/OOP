/*Problem: A vehicle rental company is expanding its services to include cars, bikes, and
future vehicle types. They need a flexible system to manage daily rates and display vehicle
details without exposing internal calculations. The goal is to ensure new vehicle types (e.g.,
scooters, trucks) can be added seamlessly while maintaining a consistent interface for
customers to view rental options.
Classes and Structure:
• Abstract Class Vehicle:
o Data Members:
▪ model (string): Stores the vehicle’s model name.
▪ rate (double): Stores the daily rental rate.
o Member Functions:
▪ getDailyRate(): Pure virtual function to return the daily rate.
▪ displayDetails(): Pure virtual function to show model and rate.

• Derived Class Car:
o Inherits model and rate from Vehicle.
o Overrides getDailyRate() and displayDetails() to provide car-specific
behavior.
• Derived Class Bike:
o Inherits model and rate from Vehicle.
o Overrides getDailyRate() and displayDetails() to provide bike-specific
behavior.

Flow:
• Create Car and Bike objects.
• Use polymorphism to call displayDetails() and getDailyRate() for each vehicle.*/


#include<iostream>
#include<string>
using namespace std;

class Vehicle {
protected:
    string model;
    double rate;
public:
    Vehicle(string m, double r): model(m), rate(r) {}
    virtual double getDailyRate() = 0;
    virtual void displayDetails() = 0; 
};

class Car : public Vehicle {
public:
    Car(string m, double r): Vehicle(m, r) {}
    
    double getDailyRate() override {
        return rate;
    } 

    void displayDetails() override {
        cout << "Car Model: " << model << endl;
        cout << "Daily Rate: $" << getDailyRate() << endl;
    }
};

class Bike : public Vehicle {
public:
    Bike(string m, double r): Vehicle(m, r) {}
    
    double getDailyRate() override {
        return rate; 
    } 

    void displayDetails() override {
        cout << "Bike Model: " << model << endl;
        cout << "Daily Rate: $" << getDailyRate() << endl;
    }
};

int main() {
    Car c1("Porsche", 500.0);
    Bike b1("Harley Fatboy", 250.0);

    Vehicle *v1 = &c1;
    Vehicle *v2 = &b1;
    
    v1->displayDetails();
    cout << "Rate via getDailyRate(): $" << v1->getDailyRate() << endl;
    
    v2->displayDetails();
    cout << "Rate via getDailyRate(): $" << v2->getDailyRate() << endl;
}
