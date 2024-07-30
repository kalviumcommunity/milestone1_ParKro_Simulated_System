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
    Vehicle obj;
    ParkingSpace obj1;
    string LicensePlate, ownerDetails, QRCcode, location;

    cout << "Enter License Plate: ";
    cin >> LicensePlate;
    cout << "Enter Owner's Details: ";
    cin >> ownerDetails;
    cout << "Enter QR Code: ";
    cin >> QRCcode;

    obj.setLicensePlate(LicensePlate);
    obj.setownerDetails(ownerDetails);
    obj.setQRcode(QRCcode);

    cout << "License Plate: " << obj.getLicensePlate() << endl;
    cout << "Owner's Details: " << obj.getownerDetails() << endl;
    cout << "QR Code: " << obj.getQRcode() << endl;

    return 0;
}
