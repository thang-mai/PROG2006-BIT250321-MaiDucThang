#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::endl;

class Student {
	private:
		string name;
		int age;
		float gpa;
	public:
		string getName() const {
			return name;
		}
		int getAge() const {
			return age;
		}
		float getGpa() {
			return gpa;
		}
		void setName(string value) {
			name = value;
		}
		void setAge(int value) {
			if (16 <= value && value <= 80) {
				age = value;
			} else {
				cout << "Tuoi khong hop le" << endl;
				age = value;
			}
		}
		void setGpa(float value) {
			if (0.0 <= value && value <= 4.0) {
				gpa = value;
			} else {
				cout << "Gpa khong hop le" << endl;
				gpa = value;
			}
		}
		void display() const {
			cout << "Ten: " << name << endl;
			cout << "Tuoi: " << age << endl;
			cout << "Gpa: " << gpa << endl;
		}
};

int main() {
	Student s;
	s.setName("Pham Cong Thoang");
	s.setAge(18);
	s.setGpa(3.99);
	s.display();
}