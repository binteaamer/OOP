#include <iostream>
#include <string>
using namespace std;

class DeviceManagement {
protected:
    int deviceID;
    string deviceType;
    double powerRating;
    bool status;

public:
    DeviceManagement(int id, string type, double power) : deviceID(id), deviceType(type), powerRating(power), status(false) {}
    virtual void turnOn() { status = true; }
    virtual void turnOff() { status = false; }
    virtual double calculatePowerUsage(int hours) { return 0; }
    string getType() { return deviceType; }
    bool getStatus() { return status; }
};

class Light : public DeviceManagement {
public:
    Light(int id, string type, double power) : DeviceManagement(id, type, power) {}
    double calculatePowerUsage(int hours) override { 
        return powerRating * hours; 
    }
};

class Fan : public DeviceManagement {
    int speedFactor;
public:
    Fan(int id, string type, double power, int speed) : DeviceManagement(id, type, power), speedFactor(speed) {}
    double calculatePowerUsage(int hours) override { 
        return powerRating * hours * speedFactor; 
    }
};

class AC : public DeviceManagement {
    double currentTemp, desiredTemp;
public:
    AC(int id, string type, double power, double ctemp, double dtemp) : DeviceManagement(id, type, power), currentTemp(ctemp), desiredTemp(dtemp) {}
    void turnOn() override { 
        status = true; 
        cout << "AC turned ON. Adjusting temperature to " << desiredTemp << "°C.\n";
    }
    void turnOff() override { 
        status = false; 
        cout << "AC turned OFF.\n";
    }
    double calculatePowerUsage(int hours) override { 
        return powerRating * hours * (1 - (currentTemp - desiredTemp) / 100); 
    }
};

class SecuritySystem : public DeviceManagement {
    friend class MaintenanceTool;  // Grant access to MaintenanceTool
public:
    SecuritySystem(int id, string type, double power) : DeviceManagement(id, type, power) {}
    void turnOn() override { 
        status = true; 
        cout << "Security System armed.\n";
    }
    void turnOff() override {
        string input;
        cout << "Enter maintenance code to turn OFF security: ";
        cin >> input;
        if (input == "1234") {  // Example authorization
            status = false;
            cout << "Security System disarmed.\n";
        } else {
            cout << "Invalid code! Security System remains ON.\n";
        }
    }
    double calculatePowerUsage(int hours) override { 
        if (status) {
            cout << "[Security Log] System active for " << hours << " hours.\n";
            return powerRating * hours; 
        }
        return 0;
    }
    friend void accessSecurityLogs(SecuritySystem& secSys, string role);
};

void accessSecurityLogs(SecuritySystem& secSys, string role) {
    if (role == "Maintenance Staff") {
        cout << "Accessing Security Logs...\n";
        cout << "Status: " << (secSys.getStatus() ? "ACTIVE" : "INACTIVE") << "\n";
    } else {
        cout << "Access Denied: Insufficient Permissions!\n";
    }
}

class MaintenanceTool {
public:
    void resetAlerts(SecuritySystem& secSys) {
        secSys.status = false;
        cout << "Maintenance Tool: Security alerts reset.\n";
    }
};

class User {
    string userID;
    string role;
    int accessLevel;
public:
    User(string id, string r, int level) : userID(id), role(r), accessLevel(level) {}
    void viewAccessibleDevices(DeviceManagement* devices[], int size) {
        cout << "Accessible Devices for " << userID << " (" << role << "):\n";
        for (int i = 0; i < size; i++) {
            string type = devices[i]->getType();
            if (role == "Maintenance Staff" || type == "Light" || type == "Fan") {
                cout << "- " << type << "\n";
            }
        }
    }
    string getRole() { return role; }
};

int main() {
    Light light1(1, "Light", 50);
    Fan fan1(2, "Fan", 75, 3);
    AC ac1(3, "AC", 1500, 30, 22);
    SecuritySystem sec1(4, "SecuritySystem", 100);

    DeviceManagement* devices[] = { &light1, &fan1, &ac1, &sec1 };
    int deviceCount = 4;

    User user1("user123", "Regular User", 1);
    User user2("admin456", "Maintenance Staff", 2);

    // Demo device control
    light1.turnOn();
    fan1.turnOn();
    ac1.turnOn();
    sec1.turnOn();

    // Demo power calculation
    cout << "Power Usage (Light, 5h): " << light1.calculatePowerUsage(5) << " Wh\n";
    cout << "Power Usage (Fan, 5h): " << fan1.calculatePowerUsage(5) << " Wh\n";
    cout << "Power Usage (AC, 5h): " << ac1.calculatePowerUsage(5) << " Wh\n";
    cout << "Power Usage (Security, 5h): " << sec1.calculatePowerUsage(5) << " Wh\n";

    // Demo user access
    user1.viewAccessibleDevices(devices, deviceCount);
    user2.viewAccessibleDevices(devices, deviceCount);

    // Demo security features
    accessSecurityLogs(sec1, user1.getRole());
    accessSecurityLogs(sec1, user2.getRole());

    MaintenanceTool tool;
    tool.resetAlerts(sec1);  // Demo friend class

    sec1.turnOff();  // Requires authorization
    return 0;
}
