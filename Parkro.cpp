#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Interface for role display
class RoleDisplay {
public:
    virtual void displayRole() const = 0;
    virtual ~RoleDisplay() {}
};

// Abstract base class
class VehicleBase : public RoleDisplay {
protected:
    string licensePlate;
    string ownerDetails;

public:
    virtual string getLicensePlate() const = 0;
    virtual void setLicensePlate(const string& licensePlate) = 0;
    virtual string getOwnerDetails() const = 0;
    virtual void setOwnerDetails(const string& ownerDetails) = 0;
    virtual void displayInfo() const = 0; // Polymorphic method
    virtual ~VehicleBase() {}
};

// Car class inheriting from VehicleBase
class Car : public VehicleBase {
private:
    string carModel;

public:
    string getLicensePlate() const override {
        return licensePlate;
    }

    void setLicensePlate(const string& licensePlate) override {
        this->licensePlate = licensePlate;
    }

    string getOwnerDetails() const override {
        return ownerDetails;
    }

    void setOwnerDetails(const string& ownerDetails) override {
        this->ownerDetails = ownerDetails;
    }

    void setCarModel(const string& model) {
        carModel = model;
    }

    string getCarModel() const {
        return carModel;
    }

    void displayInfo() const override {
        cout << "Car Details:\n";
        cout << "License Plate: " << licensePlate << endl;
        cout << "Owner Details: " << ownerDetails << endl;
        cout << "Car Model: " << carModel << endl;
    }

    void displayRole() const override {
        cout << "Role: Car" << endl;
    }
};

// Bike class inheriting from VehicleBase
class Bike : public VehicleBase {
private:
    string bikeType;

public:
    string getLicensePlate() const override {
        return licensePlate;
    }

    void setLicensePlate(const string& licensePlate) override {
        this->licensePlate = licensePlate;
    }

    string getOwnerDetails() const override {
        return ownerDetails;
    }

    void setOwnerDetails(const string& ownerDetails) override {
        this->ownerDetails = ownerDetails;
    }

    void setBikeType(const string& type) {
        bikeType = type;
    }

    string getBikeType() const {
        return bikeType;
    }

    void displayInfo() const override {
        cout << "Bike Details:\n";
        cout << "License Plate: " << licensePlate << endl;
        cout << "Owner Details: " << ownerDetails << endl;
        cout << "Bike Type: " << bikeType << endl;
    }

    void displayRole() const override {
        cout << "Role: Bike" << endl;
    }
};

// Assignment Reporter
class VehicleReporter {
private:
    const VehicleBase& vehicle;

public:
    VehicleReporter(const VehicleBase& vehicle) : vehicle(vehicle) {}

    void generateReport() const {
        cout << "Generating report for vehicle:\n";
        vehicle.displayInfo();
    }
};

int main() {
    vector<VehicleBase*> vehicles;

    int n;
    cout << "Enter the number of vehicles: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int type;
        cout << "Enter vehicle type (1 for Car, 2 for Bike): ";
        cin >> type;

        if (type == 1) {
            Car* car = new Car();
            string licensePlate, ownerDetails, carModel;

            cout << "Enter License Plate, Owner Details, and Car Model for Car " << i + 1 << ": ";
            cin >> licensePlate >> ownerDetails >> carModel;

            car->setLicensePlate(licensePlate);
            car->setOwnerDetails(ownerDetails);
            car->setCarModel(carModel);

            vehicles.push_back(car);
        } else if (type == 2) {
            Bike* bike = new Bike();
            string licensePlate, ownerDetails, bikeType;

            cout << "Enter License Plate, Owner Details, and Bike Type for Bike " << i + 1 << ": ";
            cin >> licensePlate >> ownerDetails >> bikeType;

            bike->setLicensePlate(licensePlate);
            bike->setOwnerDetails(ownerDetails);
            bike->setBikeType(bikeType);

            vehicles.push_back(bike);
        } else {
            cout << "Invalid vehicle type. Try again.\n";
            i--; // Retry input for this iteration
        }
    }

    cout << "\nVehicle Details:\n";
    for (const auto& vehicle : vehicles) {
        vehicle->displayInfo();
        VehicleReporter reporter(*vehicle);
        reporter.generateReport();
        cout << endl;
    }

    // Clean up memory
    for (auto& vehicle : vehicles) {
        delete vehicle;
    }

    vehicles.clear();
    return 0;
}
