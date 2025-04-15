/*Problem: A homeowner wants to integrate smart lights and thermostats from different
brands into a single app. The system must provide a unified way to turn devices on/off,
adjust settings, and check statuses without requiring users to interact with brand-specific
interfaces. Future devices (e.g., smart locks) should integrate without altering the core
system.
Classes and Structure:
• Abstract Class SmartDevice:
o Member Functions:

▪ turnOn(): Pure virtual function to activate the device.
▪ turnOff(): Pure virtual function to deactivate the device.
▪ getStatus(): Pure virtual function to return the device’s current state.

• Derived Class LightBulb:
o Data Members:
▪ isOn (bool): Tracks if the light is on/off.
▪ brightness (int): Stores brightness level (0-100%).
o Implements turnOn(), turnOff(), and getStatus() for light control.
• Derived Class Thermostat:
o Data Members:
▪ isOn (bool): Tracks if the thermostat is active.
▪ temperature (double): Stores the current temperature setting.
o Implements turnOn(), turnOff(), and getStatus() for temperature control.

Flow:
• Create LightBulb and Thermostat objects.
• Turn devices on/off and display their statuses.*/

#include <iostream>
#include <string>
using namespace std;

class SmartDevice {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void getStatus() = 0;
    virtual ~SmartDevice() {}
};

class LightBulb : public SmartDevice {
    bool isOn;
    double brightness;
public:
    LightBulb(double b) : isOn(false), brightness(b) {}

    void turnOn() override {
        isOn = true;
        cout << "LightBulb turned on" << endl;
    }

    void turnOff() override {
        isOn = false;
        cout << "LightBulb turned off" << endl;
    }

    void getStatus() override {
        string status = isOn ? "ON" : "OFF";
        cout << "LightBulb status: " << status 
             << ", Brightness: " << brightness << "%" << endl;
    }
    
    void setBrightness(double level) {
        brightness = level;
    }
};

class Thermostat : public SmartDevice {
    bool isOn;
    double temperature;
public:
    Thermostat(double temp) : isOn(false), temperature(temp) {}

    void turnOn() override {
        isOn = true;
        cout << "Thermostat activated" << endl;
    }

    void turnOff() override {
        isOn = false;
        cout << "Thermostat deactivated" << endl;
    }

    void getStatus() override {
        string status = isOn ? "ON" : "OFF";
        cout << "Thermostat status: " << status 
             << ", Temperature: " << temperature << "°C" << endl;
    }
    
    void setTemperature(double temp) {
        temperature = temp;
    }
};

int main() {
    LightBulb l1(50.0);
    Thermostat t1(22.5);
    
    l1.getStatus();
    t1.getStatus();
    
    l1.turnOn();
    t1.turnOn();
    
    l1.getStatus();
    t1.getStatus();
    
    l1.setBrightness(75.0);
    t1.setTemperature(24.0);
    
    l
