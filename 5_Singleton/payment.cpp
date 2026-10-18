#include <iostream>
#include <mutex>
using namespace std;

class PaymentProcessor {
private: 
    static mutex mtx;
    PaymentProcessor() {
        cout << "PaymentProcessor instance created." << endl;
    }
    static PaymentProcessor* instance;
public:
    static PaymentProcessor* getInstance() {
        mtx.lock();
        if(instance == nullptr) {
            instance = new PaymentProcessor();
        }
        mtx.unlock();
        return instance;
    }

    void processPayment(int amount) {
        cout << "Processing payment of amount: " << amount << endl;
    }
};

PaymentProcessor* PaymentProcessor::instance = nullptr;
mutex PaymentProcessor::mtx;

int main() {
    PaymentProcessor* processor1 = PaymentProcessor::getInstance();
    processor1->processPayment(100);

    PaymentProcessor* processor2 = PaymentProcessor::getInstance();
    processor2->processPayment(200);

    if (processor1 == processor2) {
        cout << "Both instances are the same." << endl;
    } else {
        cout << "Instances are different." << endl;
    }

    return 0;
}