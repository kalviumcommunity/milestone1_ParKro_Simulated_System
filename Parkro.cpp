#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Vehicle{
    private:
    string LicensePlate;
    string ownersDetails;
    string QRcode;

    public:
    string getLicensePlate(){
        return LicensePlate; 
    }
    void setLicensePlate(string s){
        LicensePlate = s;
    }
    string getownerDetails(){
        return ownersDetails; 
    }
    void setownerDetails(string x){
        ownersDetails = x;
    }
    string getQRcode(){
        return QRcode; 
    }
    void setQRcode(string y){
        QRcode = y;
    }
};
class ParkingSpace{
    private:
    string location;
    bool Availability;
    
    public:
    string getlocation(){
        return location;
    }
    void setlocation(string b){
        location = b;
    }
    bool getAvailability(){
        return Availability;
    }
    void setAvailability(bool a){
        Availability = a;
    }

};


int main(){
    Vehicle obj;
    ParkingSpace obj1;
    string LicensePlate,ownerDetails,QRCcode,location;
    cin>>LicensePlate>>ownerDetails>>QRCcode;
    obj.setLicensePlate(LicensePlate);
    obj.setownerDetails(ownerDetails);
    obj.setQRcode(QRCcode);
    cout<<obj.getLicensePlate()<<endl;
    cout<<obj.getownerDetails()<<endl;
    cout<<obj.getQRcode()<<endl;




    


    return 0;
}



