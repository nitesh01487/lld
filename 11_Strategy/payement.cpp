#include <iostream>

using namespace std;

class PaymentStrategy {
public:
    virtual void pay(int amount) = 0;
    virtual ~PaymentStrategy() = default;
};

class CreditCardPayment : public PaymentStrategy {
private:
    string cardNumber;
    string cardHolderName;
public:
    CreditCardPayment(string cardNumber, string cardHolderName) : cardNumber(cardNumber), cardHolderName(cardHolderName) {}
    void pay(int amount) override {
        cout << "Paid " << amount << " using Credit Card. Card Number: " << cardNumber << ", Card Holder: " << cardHolderName << endl;
    }
};

class PayPalPayment : public PaymentStrategy {
private:    
    string email;
public:
    PayPalPayment(string email) : email(email) {}
    void pay(int amount) override {
        cout << "Paid " << amount << " using PayPal. Email: " << email << endl;
    }
};


class BitcoinPayment : public PaymentStrategy {
private:
    string walletAddress;
public:
    BitcoinPayment(string walletAddress) : walletAddress(walletAddress) {}
    void pay(int amount) override {
        cout << "Paid " << amount << " using Bitcoin. Wallet Address: " << walletAddress << endl;
    }
};

class PaymentProcessor {
private:
    PaymentStrategy* paymentStrategy;
public:
    PaymentProcessor(PaymentStrategy* strategy) : paymentStrategy(strategy) {}

    void setPaymentStrategy(PaymentStrategy* strategy) {
        paymentStrategy = strategy;
    }

    void processPayment(int amount) {
        paymentStrategy->pay(amount);
    }
};

int main() {
    PaymentStrategy* creditCardPayment = new CreditCardPayment("1234-5678-9876-5432", "John Doe");
    PaymentStrategy* paypalPayment = new PayPalPayment("john.doe@example.com");
    PaymentStrategy* bitcoinPayment = new BitcoinPayment("1A1zP1eP5QGefi2DMPTfTL5SLmv7DivfNa");

    PaymentProcessor paymentProcessor(creditCardPayment);
    paymentProcessor.processPayment(100);

    paymentProcessor.setPaymentStrategy(paypalPayment);
    paymentProcessor.processPayment(200);

    paymentProcessor.setPaymentStrategy(bitcoinPayment);
    paymentProcessor.processPayment(300);

    delete creditCardPayment;
    delete paypalPayment;
    delete bitcoinPayment;

    return 0;
}   