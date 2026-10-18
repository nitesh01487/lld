#include <iostream>

using namespace std;

class OrderHandler {
protected:
    OrderHandler* nextHandler;
public:
    OrderHandler(OrderHandler *nextHandler) : nextHandler(nextHandler) {};

    virtual void handleOrder(const string& order) = 0;
    virtual ~OrderHandler() = default;
};

class orderValidationHandler : public OrderHandler {
public:
    orderValidationHandler(OrderHandler *nextHandler) : OrderHandler(nextHandler) {};

    void handleOrder(const string& order) override {
        cout << "Validating order: " << order << endl;
        if (nextHandler) {
            nextHandler->handleOrder(order);
        }
    }
};

class paymentProcessingHandler : public OrderHandler {
public:
    paymentProcessingHandler(OrderHandler *nextHandler) : OrderHandler(nextHandler) {};

    void handleOrder(const string& order) override {
        cout << "Processing payment for order: " << order << endl;
        if (nextHandler) {
            nextHandler->handleOrder(order);
        }
    }
};

class orderPreparationHandler : public OrderHandler {
public:
    orderPreparationHandler(OrderHandler *nextHandler) : OrderHandler(nextHandler) {};

    void handleOrder(const string& order) override {
        cout << "Preparing order: " << order << endl;
        if (nextHandler) {
            nextHandler->handleOrder(order);
        }
    }
};

class deliveryAssignmentHandler : public OrderHandler {
public:
    deliveryAssignmentHandler(OrderHandler *nextHandler) : OrderHandler(nextHandler) {};

    void handleOrder(const string& order) override {
        cout << "Assigning delivery for order: " << order << endl;
        if (nextHandler) {
            nextHandler->handleOrder(order);
        }
    }
};

class orderTrackingHandler : public OrderHandler {
public:
    orderTrackingHandler(OrderHandler *nextHandler) : OrderHandler(nextHandler) {};

    void handleOrder(const string& order) override {
        cout << "Tracking order: " << order << endl;
        if (nextHandler) {
            nextHandler->handleOrder(order);
        }
    }
};

int main() {
    // OrderHandler* trackingHandler       = new orderTrackingHandler(nullptr);
    // OrderHandler* deliveryHandler       = new deliveryAssignmentHandler(trackingHandler);
    // OrderHandler* preparationHandler    = new orderPreparationHandler(deliveryHandler);
    // OrderHandler* paymentHandler        = new paymentProcessingHandler(preparationHandler);
    // OrderHandler* validationHandler     = new orderValidationHandler(paymentHandler);

    // string order = "Order#12345";
    // validationHandler->handleOrder(order);

    // delete validationHandler;
    // delete paymentHandler;
    // delete preparationHandler;
    // delete deliveryHandler;
    // delete trackingHandler;

    OrderHandler* orderProcessor = new orderTrackingHandler(
                                                                new orderValidationHandler(
                                                                    new paymentProcessingHandler(
                                                                        new orderPreparationHandler(
                                                                            new deliveryAssignmentHandler(
                                                                                new orderTrackingHandler(nullptr)
                                                                            )
                                                                        )
                                                                    )
                                                                )
                                                            );

    string order = "Order#12345";
    orderProcessor->handleOrder(order);

    return 0;
}