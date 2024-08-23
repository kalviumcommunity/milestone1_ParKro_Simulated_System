#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Vehicle {
private:

    string LicensePlate;
    string ownersDetails;
    string QRcode;

public:
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
    vector<Vehicle*> vehicles;
    vector<ParkingSpace> parkingSpaces;
    
    int n;
    cout << "Enter the number of vehicles: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Vehicle* obj = new Vehicle();
        string LicensePlate, ownerDetails, QRcode;
        
        cout << "Enter License Plate, Owner Details, and QR Code for Vehicle " << i + 1 << ": ";
        cin >> LicensePlate >> ownerDetails >> QRcode;
        
        obj->setLicensePlate(LicensePlate);
        obj->setownerDetails(ownerDetails);
        obj->setQRcode(QRcode);
        
        vehicles.push_back(obj);
    }

    cout << "\nVehicle Details:\n";
    for (int i = 0; i < vehicles.size(); i++) {
        cout << "Vehicle " << i + 1 << ":\n";
        cout << "License Plate: " << vehicles[i]->getLicensePlate() << endl;
        cout << "Owner Details: " << vehicles[i]->getownerDetails() << endl;
        cout << "QR Code: " << vehicles[i]->getQRcode() << endl;
        cout << endl;

        delete vehicles[i];
    }
    vehicles.clear();

    return 0;
}
