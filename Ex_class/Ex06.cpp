#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Employee {
private:
    string name;
    string department;
    double salary;
public:
    Employee() {
        name = "Unknown";
        department = "Unknown";
        salary = 0.0;
    }
    Employee& setName(string name) {
        this->name = name;
        return *this;
    }
    Employee& setDepartment(string department) {
        this->department = department;
        return *this;
    }
    Employee& setSalary(double salary) {
        if (salary >= 0) {
            this->salary = salary;
        } else {
            cout << "Loi: Luong khong duoc am!" << endl;
        }
        return *this;
    }
    void display() const {
        cout << "Nhan vien: " << name 
             << " | Phong: " << department 
             << " | Luong: " << salary << " VND" << endl;
    }
};

int main() {
    Employee e;
    e.setName("Minh").setDepartment("IT").setSalary(15000000).display();
    return 0;
}