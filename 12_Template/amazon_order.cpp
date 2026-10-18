#include <iostream>

using namespace std;

class OrderPocessingTemplate {
public:
    virtual ~OrderPocessingTemplate() {}

    void processOrder() {
        validateOrder();
        processPayment();
        shipOrder();
        sendConfirmation();
    }

protected:
    virtual void validateOrder() = 0;
    virtual void processPayment() = 0;
    virtual void shipOrder() = 0;
    virtual void sendConfirmation() = 0;
};

class InternationalOrder : public OrderPocessingTemplate {
protected:
    void validateOrder() override {
        cout << "Validating international order..." << endl;
    }

    void processPayment() override {
        cout << "Processing international payment..." << endl;
    }

    void shipOrder() override {
        cout << "Shipping international order..." << endl;
    }

    void sendConfirmation() override {
        cout << "Sending confirmation for international order..." << endl;
    }
};

class DomesticOrder : public OrderPocessingTemplate {
protected:
    void validateOrder() override {
        cout << "Validating domestic order..." << endl;
    }

    void processPayment() override {
        cout << "Processing domestic payment..." << endl;
    }

    void shipOrder() override {
        cout << "Shipping domestic order..." << endl;
    }

    void sendConfirmation() override {
        cout << "Sending confirmation for domestic order..." << endl;
    }
};

int main() {
    OrderPocessingTemplate* internationalOrder = new InternationalOrder();
    internationalOrder->processOrder();
    delete internationalOrder;

    cout << endl;

    OrderPocessingTemplate* domesticOrder = new DomesticOrder();
    domesticOrder->processOrder();
    delete domesticOrder;

    return 0;
}