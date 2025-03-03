/*Keeping in mind our previous car example, write a class that represents a car, and use aggregation and 
composition to combine different components like the engine, wheels, headlights and steering to create the 
car object.

Hint: create the individual classes first before performing the composition. Remember 
that for aggregation, you will need pointers! You’ll be needing constructors and
*/
#include<iostream>
#include<string>
using namespace std;

class engine{
   public:
    engine() { cout << "Engine created.\n"; }
    void start() { cout << "Engine started.\n"; }
};
class wheels {
    public:
    wheels() { cout << "Wheels created.\n"; }
    void rotate() { cout << "Wheels are moving.\n"; }
};
class headlights{
    public:
    headlights() { cout << "Headlights installed.\n"; }
    void turnOn() { cout << "Headlights turned on.\n"; }

};
class steering {
    public:
    steering() { cout << "Steering installed.\n"; }
    void turnLeft() { cout << "Turning left.\n"; }
    void turnRight() { cout << "Turning right.\n"; }
};
class Driver {
    public:
        string name;
        Driver(string n) : name(n) { cout << "Driver " << name << " assigned.\n"; }
        void drive() { cout << name << " is driving the car.\n"; }
    };


class car{
    engine engine;
    wheels wheels;
    headlights headlights;
    steering steering;
    Driver* driver;
    public:
    car(Driver* d = nullptr) : driver(d) {
        cout << "Car is assembled.\n";
    }

    void assignDriver(Driver* d) {
        driver=d;}
        void startCar() {
            engine.start();
            wheels.rotate();
            headlights.turnOn();
            if (driver)
                driver->drive();
            else
                cout << "No driver assigned!\n";
        }
    
        void turnLeft() { steering.turnLeft(); }
        void turnRight() { steering.turnRight(); }
    };
    int main() {
        
        Driver d1("Abeeha");

        car myCar(&d1);
        myCar.startCar();
        myCar.turnLeft();
    
        cout << "\n--- Creating a car without a driver ---\n";
        car carWithoutDriver;
        carWithoutDriver.startCar();  
    
        return 0;
    }
