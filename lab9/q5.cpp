/*Problem: A fitness app wants to help users track calories burned during activities like
running and cycling. Each activity requires unique calculations (e.g., distance vs. speed), but
the app must present results consistently. The system should allow adding new activities
(e.g., swimming) in the future.
Classes and Structure:
• Abstract Class Activity:
o Member Function:
▪ calculateCaloriesBurned(): Pure virtual function to compute calories.

• Derived Class Running:
o Data Members:
▪ distance (double): Stores distance in kilometers.
▪ time (double): Stores duration in minutes.
o Implements calculateCaloriesBurned() for running.
• Derived Class Cycling:

o Data Members:
▪ speed (double): Stores speed in km/h.
▪ time (double): Stores duration in hours.
o Implements calculateCaloriesBurned() for cycling.

Flow:
• Create Running and Cycling objects.
• Display calories burned for each activity. */


#include <iostream>
using namespace std;

class Activity {
public:
    virtual double calculateCaloriesBurned() const = 0;
    virtual ~Activity() {}
};

class Running : public Activity {
    double distance; // km
    double time;    // minutes
public:
    Running(double d, double t) : distance(d), time(t) {}
    double calculateCaloriesBurned() const override {
        return distance * 60; // assuming 60 calories per km
    }
};

class Cycling : public Activity {
    double speed; // km/h
    double time;  // hours
public:
    Cycling(double s, double t) : speed(s), time(t) {}
    double calculateCaloriesBurned() const override {
        return speed * time * 25; //  met formula from google
    }
};

int main() {
    
    Running run(5.0, 30.0);  // 5km in 30 minutes
    Cycling cycle(18.0, 1.5); // 18km/h for 1.5 hours
    
    cout << "Running calories burned: " << run.calculateCaloriesBurned() << endl;
    cout << "Cycling calories burned: " << cycle.calculateCaloriesBurned() << endl;
    
    return 0;
}
