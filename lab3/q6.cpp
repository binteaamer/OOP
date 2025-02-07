#include <iostream>
#include <string>

using namespace std;

class Smartphone {
private:
    string company;
    string model;
    string resolution;
    int ram;
    int rom;
    int storage;

public:
    void setCompany(string c) { company = c; }
    void setModel(string m) { model = m; }
    void setResolution(string r) { resolution = r; }
    void setRAM(int r) { ram = r; }
    void setROM(int r) { rom = r; }
    void setStorage(int s) { storage = s; }

    string getCompany() { return company; }
    string getModel() { return model; }
    string getResolution() { return resolution; }
    int getRAM() { return ram; }
    int getROM() { return rom; }
    int getStorage() { return storage; }

    void makeCall() { cout << "Making a phone call..." << endl; }
    void sendMessage() { cout << "Sending a message..." << endl; }
    void connectWifi() { cout << "Connecting to WiFi..." << endl; }
    void browseInternet() { cout << "Browsing the internet..." << endl; }
};

int main() {
    Smartphone phone1, phone2;

    phone1.setCompany("Apple");
    phone1.setModel("iPhone 15");
    phone1.setResolution("2532x1170");
    phone1.setRAM(6);
    phone1.setROM(128);
    phone1.setStorage(256);

    phone2.setCompany("Samsung");
    phone2.setModel("Galaxy S23");
    phone2.setResolution("3088x1440");
    phone2.setRAM(8);
    phone2.setROM(256);
    phone2.setStorage(512);

    cout << "Smartphone 1 Details:" << endl;
    cout << "Company: " << phone1.getCompany() << endl;
    cout << "Model: " << phone1.getModel() << endl;
    cout << "Resolution: " << phone1.getResolution() << endl;
    cout << "RAM: " << phone1.getRAM() << "GB" << endl;
    cout << "ROM: " << phone1.getROM() << "GB" << endl;
    cout << "Storage: " << phone1.getStorage() << "GB" << endl;
    phone1.makeCall();
    phone1.sendMessage();

    cout << "\nSmartphone 2 Details:" << endl;
    cout << "Company: " << phone2.getCompany() << endl;
    cout << "Model: " << phone2.getModel() << endl;
    cout << "Resolution: " << phone2.getResolution() << endl;
    cout << "RAM: " << phone2.getRAM() << "GB" << endl;
    cout << "ROM: " << phone2.getROM() << "GB" << endl;
    cout << "Storage: " << phone2.getStorage() << "GB" << endl;
    phone2.connectWifi();
    phone2.browseInternet();

    return 0;
}
