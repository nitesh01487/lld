#include <iostream>

using namespace std;

class NetworkDevice {
public:
    virtual void displayInfo() = 0;
    virtual NetworkDevice* clone() const = 0;
    virtual ~NetworkDevice() = default;
};

class Router : NetworkDevice {
private:
    string model;
    string ipAddress;
    string name;
public:
    Router(string model, string ipAddress, string name) : model(model), ipAddress(ipAddress), name(name) {};

    void displayInfo() {
        cout << "Router Model: " << model << endl;
        cout << "IP Address: " << ipAddress << endl;
        cout << "Name: " << name << endl;
    }

    NetworkDevice* clone() const {
        return new Router(model, ipAddress, name);
    }
};

class Switch : NetworkDevice {
private:
    string model;
    string ipAddress;
    string name;
public:
    Switch(string model, string ipAddress, string name) : model(model), ipAddress(ipAddress), name(name) {};

    void displayInfo() {
        cout << "Switch Model: " << model << endl;
        cout << "IP Address: " << ipAddress << endl;
        cout << "Name: " << name << endl;
    }

    NetworkDevice* clone() const {
        return new Switch(model, ipAddress, name);
    }
};

int main() {
    Router* router1 = new Router("RTX-1000", "192.168.1.1", "MainRouter");
    Switch* switch1 = new Switch("SWX-2000", "192.168.1.2", "MainSwitch");

    NetworkDevice* router2 = router1->clone();
    NetworkDevice* switch2 = switch1->clone();

    cout << "Original Router:" << endl;
    router1->displayInfo();

    cout << "Cloned Router:" << endl;
    router2->displayInfo();

    cout << "Original Switch:" << endl;
    switch1->displayInfo();

    cout << "Cloned Switch:" << endl;
    switch2->displayInfo();

    delete router1;
    delete switch1;
    delete router2;
    delete switch2;

    return 0;
}