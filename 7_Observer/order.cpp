#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
class Order;

class Observer {
public:
    virtual void update(Order* order) = 0;
    virtual ~Observer() = default;
};

class Customer : public Observer {
private:
    string name;
public:
    Customer(string name) : name(name) {}
    void update(Order* order) override;
};

class Restaurant : public Observer {
private:
    string name;
public:
    Restaurant(string name) : name(name) {}
    void update(Order* order) override;
};

class DeliveryDriver : public Observer {
private:
    string name;
public:
    DeliveryDriver(string name) : name(name) {}
    void update(Order* order) override;
};


class CallCenter : public Observer {
private:
    string name;
public:
    CallCenter(string name) : name(name) {}
    void update(Order* order) override;
};


class Order {
private:
    string orderId;
    string status;
    vector<Observer*> observers;
public:
    Order(string orderId) : orderId(orderId), status("Pending") {};

    string getStatus() const {
        return status;
    }

    string getOrderId() const {
        return orderId;
    }

    void attach(Observer* observer) {
        observers.push_back(observer);
    }
    void detach(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }
    void notify() {
        for (Observer* observer : observers) {
            observer->update(this);
        }
    }
    void updateStatus(string newStatus) {
        status = newStatus;
        notify();
    }
};

void Customer::update(Order* order) {
    cout << "Customer : Hi ! " << name << "your order id : "
         << order->getOrderId() << " is " << order->getStatus() << endl;
}

void Restaurant::update(Order* order) {
    cout << "Restaurant : Hi ! " << name << " your order id : "
         << order->getOrderId() << " is " << order->getStatus() << endl;
}

void DeliveryDriver::update(Order* order) {
    cout << "Delivery Service : Hi ! " << name << " your order id : "
         << order->getOrderId() << " is " << order->getStatus() << endl;
}

void CallCenter::update(Order* order) {
    cout << "Call Center : Hi ! " << name << " your order id : "
         << order->getOrderId() << " is " << order->getStatus() << endl;
}

int main() {
    Order* order = new Order("12345");

    Customer* customer = new Customer("Alice");
    Restaurant* restaurant = new Restaurant("Pizza Place");
    DeliveryDriver* driver = new DeliveryDriver("Bob");
    CallCenter* callCenter = new CallCenter("Call Center 1");

    order->attach(customer);
    order->attach(restaurant);
    order->attach(driver);
    order->attach(callCenter);

    order->updateStatus("Preparing");
    cout << "########################### " << endl;
    order->updateStatus("Out for Delivery");
    cout << "########################### " << endl;
    order->detach(restaurant);
    order->updateStatus("Delivered");

    return 0;
}