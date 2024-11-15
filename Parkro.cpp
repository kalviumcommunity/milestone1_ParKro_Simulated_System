#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Base class
class VehicleBase {
public:
    virtual string getLicensePlate() = 0;
    virtual void setLicensePlate(string LicensePlate) = 0;
    virtual string getownerDetails() = 0;
    virtual void setownerDetails(string ownersDetails) = 0;
    virtual void displayInfo() = 0; // Polymorphic method
    virtual ~VehicleBase() {}
};

// Derived class 1: Car
class Car : public VehicleBase {
private:
    string LicensePlate;
    string ownersDetails;
    string carModel;

public:
    string getLicensePlate() override {
        return LicensePlate;
    }
    void setLicensePlate(string LicensePlate) override {
        this->LicensePlate = LicensePlate;
    }
    string getownerDetails() override {
        return ownersDetails;
    }
    void setownerDetails(string ownersDetails) override {
        this->ownersDetails = ownersDetails;
    }
    void setCarModel(string model) {
        carModel = model;
    }
    string getCarModel() {
        return carModel;
    }
    void displayInfo() override {
        cout << "Car Details:\n";
        cout << "License Plate: " << LicensePlate << endl;
        cout << "Owner Details: " << ownersDetails << endl;
        cout << "Car Model: " << carModel << endl;
    }
};

// Derived class 2: Bike
class Bike : public VehicleBase {
private:
    string LicensePlate;
    string ownersDetails;
    string bikeType;

public:
    string getLicensePlate() override {
        return LicensePlate;
    }
    void setLicensePlate(string LicensePlate) override {
        this->LicensePlate = LicensePlate;
    }
    string getownerDetails() override {
        return ownersDetails;
    }
    void setownerDetails(string ownersDetails) override {
        this->ownersDetails = ownersDetails;
    }
    void setBikeType(string type) {
        bikeType = type;
    }
    string getBikeType() {
        return bikeType;
    }
    void displayInfo() override {
        cout << "Bike Details:\n";
        cout << "License Plate: " << LicensePlate << endl;
        cout << "Owner Details: " << ownersDetails << endl;
        cout << "Bike Type: " << bikeType << endl;
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
            string LicensePlate, ownerDetails, carModel;

            cout << "Enter License Plate, Owner Details, and Car Model for Car " << i + 1 << ": ";
            cin >> LicensePlate >> ownerDetails >> carModel;

            car->setLicensePlate(LicensePlate);
            car->setownerDetails(ownerDetails);
            car->setCarModel(carModel);

            vehicles.push_back(car);
        } else if (type == 2) {
            Bike* bike = new Bike();
            string LicensePlate, ownerDetails, bikeType;

            cout << "Enter License Plate, Owner Details, and Bike Type for Bike " << i + 1 << ": ";
            cin >> LicensePlate >> ownerDetails >> bikeType;

            bike->setLicensePlate(LicensePlate);
            bike->setownerDetails(ownerDetails);
            bike->setBikeType(bikeType);

            vehicles.push_back(bike);
        } else {
            cout << "Invalid vehicle type. Try again.\n";
            i--; // Retry input for this iteration
        }
    }

    cout << "\nVehicle Details:\n";
    for (int i = 0; i < vehicles.size(); i++) {
        vehicles[i]->displayInfo(); // Polymorphic call
        cout << endl;
        delete vehicles[i]; // Clean up memory
    }

    vehicles.clear();
    return 0;
}
