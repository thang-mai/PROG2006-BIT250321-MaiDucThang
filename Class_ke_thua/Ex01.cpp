#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Animal {
    protected:
        string name;
        int age;
    public:
        string getName() const {
            return name;
        }
        int getAge() const {
            return age;
        }
        void setName(string value) {
            name = value;
        }
        void setAge(int value) {
            age = value;
        }
        void eat() {
            cout << name << " is eating" << endl;
        }
};

class Dog : public Animal {
    private:
        string breed;
    public:
        string getBreed() const {
            return breed;
        }
        void setBreed(string value) {
            breed = value;
        }
        void bark() {
            cout << name << " is barking " << endl;
        }
        void display() {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Breed: " << breed << endl;
        }
};

int main() {
    Dog d;
    d.setName("Vang");
    d.setAge(2);
    d.setBreed("Cho co");
    d.eat();
    d.bark();
    d.display();
    return 0;
}