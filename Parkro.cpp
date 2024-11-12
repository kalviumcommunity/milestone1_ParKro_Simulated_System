#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class VehicleBase{
    public:
    virtual string getLicensePlate() = 0;
    virtual void setLicensePlate(string LicensePlate)=0;
    virtual string getownerDetails() = 0;
    virtual void setownerDetails(string ownersDetails)=0;
    virtual string getQRcode() = 0;
    virtual void setQRcode(string QRcode)=0;
    virtual ~VehicleBase(){}
};

//concept of inheritance
class Vehicle:public VehicleBase {
private:

    string LicensePlate;
    string ownersDetails;
    string QRcode;

    static int totalVehicles;

public:
    Vehicle(){
        incrementTotalVehicle();
    }
    ~Vehicle(){
        decrementTotalVehicle();
    }
    string getLicensePlate() {
        return LicensePlate;
    }
    void setLicensePlate(string LicensePlate) {
        this->LicensePlate = LicensePlate;
    }
    string getownerDetails() {
        return ownersDetails;
    }
    void setownerDetails(string ownersDetails) {
        this->ownersDetails = ownersDetails;
    }
    string getQRcode() {
        return QRcode;
    }
    void setQRcode(string QRcode) {
        this->QRcode = QRcode;
    }
    static void incrementTotalVehicle(){
        totalVehicles++;
    }
    static void decrementTotalVehicle(){
        totalVehicles--;
    }
    static int getTotalVehicle(){
        return totalVehicles;
    }
};
int Vehicle::totalVehicles=0;

class Car : public Vehicle {
private:
    string carModel;

public:
    void setCarModel(string model) {
        carModel = model;
    }
    string getCarModel() {
        return carModel;
    }

    void displayCarInfo() {
        cout << "Car License Plate: " << getLicensePlate() << endl;
        cout << "Owner Details: " << getownerDetails() << endl;
        cout << "QR Code: " << getQRcode() << endl;
        cout << "Car Model: " << carModel << endl;
    }
};

class ParkingSpace {
private:
    string location;
    bool Availability;

public:
    string getlocation() {
        return location;
    }
    void setlocation(string location) {
        this->location = location;
    }
    bool getAvailability() {
        return Availability;
    }
    void setAvailability(bool Availability) {
        this->Availability = Availability;
    }
};

int main() {
    vector<VehicleBase*> vehicles;
    vector<ParkingSpace> parkingSpaces;
    
    int n;
    cout << "Enter the number of vehicles: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Car* car = new Car();
        string LicensePlate, ownerDetails, QRcode, carModel;

        cout << "Enter License Plate, Owner Details, QR Code, and Car Model for Car " << i + 1 << ": ";
        cin >> LicensePlate >> ownerDetails >> QRcode >> carModel;

        car->setLicensePlate(LicensePlate);
        car->setownerDetails(ownerDetails);
        car->setQRcode(QRcode);
        car->setCarModel(carModel);

        vehicles.push_back(car);
    }

    cout << "\nCar Details:\n";
    for (int i = 0; i < vehicles.size(); i++) {
        Car* car = dynamic_cast<Car*>(vehicles[i]);
        if (car) {
            cout << "Car " << i + 1 << ":\n";
            car->displayCarInfo();
            cout << endl;
        }
        delete vehicles[i];
    }

    vehicles.clear();
    cout << "Total number of vehicles currently: " << Vehicle::getTotalVehicle() << endl;

    return 0;
}