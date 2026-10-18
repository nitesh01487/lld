#include <iostream>

using namespace std;

class RideService {
public:
    void bookRide(const string& pickupLocation, const string& dropLocation) {
        cout << "Booking a ride from " << pickupLocation << " to " << dropLocation << endl;
    }
    
    void cancelRide(const string& rideId) {
        cout << "Cancelling the ride with ID: " << rideId << endl;
    }
};

class RideCommand {
public:
    virtual void execute() = 0;
    virtual ~RideCommand() = default;
};

class BookRideCommand : public RideCommand {
private:
    RideService* rideService;
    string pickupLocation;
    string dropLocation;
public:
    BookRideCommand(RideService* service, const string& pickup, const string& drop)
        : rideService(service), pickupLocation(pickup), dropLocation(drop) {};
    void execute() override {
        rideService->bookRide(pickupLocation, dropLocation);
    }
};

class CancelRideCommand : public RideCommand {
private:
    RideService* rideService;
    string rideId;
public:
    CancelRideCommand(RideService* service, const string& id)
        : rideService(service), rideId(id) {};
    void execute() override {
        rideService->cancelRide(rideId);
    }
};

class RideInvoker {
public:
    void executeCommand(RideCommand* command) {
        command->execute();
    }
};

int main() {
    RideService* rideService = new RideService();
    RideInvoker* invoker = new RideInvoker();

    RideCommand* bookCommand = new BookRideCommand(rideService, "Location A", "Location B");
    RideCommand* cancelCommand = new CancelRideCommand(rideService, "RIDE123");

    invoker->executeCommand(bookCommand);
    invoker->executeCommand(cancelCommand);

    delete bookCommand;
    delete cancelCommand;
    delete rideService;
    delete invoker;

    return 0;
}