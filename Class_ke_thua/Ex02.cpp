#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class Vehicle {
    protected:
        string brand;
        int year;
    public:
        Vehicle(string b, int y) {
            brand = b;
            year = y;
            cout << "Vehicle ctor" << endl;
        }
        ~Vehicle() {
            cout << "Vehicle dtor" << endl;
        }
        string getBrand() const {
            return brand;
        }
        int getYear() const {
            return year;
        }
};

class Car : public Vehicle {
    private: 
        int numDoors;
    public:
        Car(string b, int y, int d) : Vehicle(b, y) {
            numDoors = d;
            cout << "Car ctor" << endl;
        }
        ~Car() {
            cout << "Car dtor" << endl;
        }
        int getNumDoors() const {
            return numDoors;
        }
        void displayInfo() {
            cout << "Brand: " << getBrand()
                 << ", Year: " << getYear()
                 << ", Number of Doors: " << getNumDoors() << endl;
        }
};

int main() {
    Car c("Toyota", 2020, 4);
    c.displayInfo();
    return 0;
}