#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class Person {
    protected:
        string name;
        int age;
    public:
        Person(string n, int a) : name(n), age(a) {}
        void display() {
            cout << "Name: " << name << ", Age: " << age ;
        }
};

class Employee : public Person {
    private:
        int employeeID;
        double salary;
    public:
        Employee(string n, int a, int id, double sal) : Person(n, a), employeeID(id), salary(sal) {}
        void display() {
            Person::display();
            cout << ", Employee ID: " << employeeID << ", Salary: " << salary << endl;
        }
};

class Manager : public Employee {
    private:
        string department;
        int teamSize;
    public:
        Manager(string n, int a, int id, double sal, string dept, int size) : Employee(n, a, id, sal), department(dept), teamSize(size) {}
        void display() {
            Employee::display();
            cout << ", Department: " << department << ", Team Size: " << teamSize << endl;
        }
};

int main() {
    Manager m("Alice", 35, 1001, 75000.0, "Sales", 10);
    m.display();
    return 0;
}