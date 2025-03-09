#include <iostream>
#include <vector>
#include <string>
using namespace std;
using std::cout;
using std::cin;

class Vehicle{
    protected:
        string brand;
        int year;
    public:
        Vehicle(string, int);
        virtual void showInfo();
        virtual ~Vehicle();
};

Vehicle::Vehicle(string _brand, int _year) : brand(_brand), year(_year){}
Vehicle::~Vehicle(){};

void Vehicle::showInfo(){
    cout<<"Brand: "<<brand<<" | Year: "<< year;
}
/// ///
class Car : public Vehicle{
    protected:
        int doors;
    public:
        Car(string, int, int);
        void showInfo();
};

Car::Car(string _brand, int _year, int _doors) : Vehicle(_brand, _year){
    doors = _doors;
};

void Car::showInfo(){
    Vehicle::showInfo();
    cout<<" |Doors "<<doors<<"\n";
}
/// ///
class Truck : public Vehicle{
    protected:
        int  loadCapacity;
    public:
    Truck(string, int, int);
        void showInfo();
};

Truck::Truck(string _brand, int _year, int _loadCapacity) : Vehicle(_brand, _year){
    loadCapacity = _loadCapacity;
};

void Truck::showInfo(){
    Vehicle::showInfo();
    cout<<" |Load Capacity "<<loadCapacity<<"\n";
}

//////

void addNewVehicle(vector<Vehicle*> &vehicles){
    int newVehiclesNumber;
    int vehicleType;
    cout<<"What type of vehicle, car (enter 1) or truck (enter 2)? ";
    try
    {
        cin>>vehicleType;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    cout<<"How Many vehicles you would like add? ";
    try
    {
        cin>>newVehiclesNumber;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    if (vehicleType != 1 && vehicleType != 2) {
        cout << "Invalid vehicle type." << endl;
        return;
    }
    if(vehicleType == 1){
        for (int i = 0; i < newVehiclesNumber; i++)
        {
            string _brand;
            int _year;
            int _doors;
            cin.ignore();
            cout<<"Brand of the car number "<<i + 1<<": ";
            getline(cin, _brand);
            cout<<"Year of the car number "<<i + 1<<": ";
            cin>>_year;
            cout<<"Doors of the car number "<<i + 1<<": ";
            cin>>_doors;
            vehicles.push_back(new Car(_brand, _year, _doors));
            cin.ignore();
            
        }
    }
    if(vehicleType == 2){
        for (int i = 0; i < newVehiclesNumber; i++)
        {
            string _brand;
            int _year;
            int _loadCapacity;
            cin.ignore();
            cout<<"Brand of the truck number "<<i + 1<<": ";
            getline(cin, _brand);
            cout<<"Year of the truck number "<<i + 1<<": ";
            cin>>_year;
            cout<<"Load Capacity of the truck number "<<i + 1<<": ";
            cin>>_loadCapacity;
            vehicles.push_back(new Truck(_brand, _year, _loadCapacity));
            cin.ignore();
            
        }
        //cout<<vehicles.size()<<"\n";
    }
    

    
    
}


void showVehiclesData(vector<Vehicle*> &vehicles){
    for (Vehicle* vehicle : vehicles)
    {
        vehicle->showInfo();
    }
    
}



int main(){
    static vector<Vehicle*> vehicles;
    int userOption;
    do
    {   
        cout<<"1 to add a new vehicle."<<endl;
        cout<<"2 to show all vehicles."<<endl;
        cout<<"3 to close program."<<endl;
        try
        {
            cin>>userOption;
        }
        catch(const std::exception& e)
        {
            cout<<"Must be a number";
            std::cerr << e.what() << '\n';
        }
        
        
        switch (userOption)
        {
        case 1:
            addNewVehicle(vehicles);
            break;
        case 2:
            showVehiclesData(vehicles);
            break;
        default:
            break;
        }
    } while (userOption != 3);
    
    for (auto& vehicle : vehicles) {
        delete vehicle; 
    }
    return 0;
}


