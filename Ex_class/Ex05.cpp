#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Rectangle {
private:
    const int id;
    double width;
    double height;
public:
    Rectangle(int i, double w, double h) : id(i) {
        setWidth(w);
        setHeight(h);
    }
    int getId() const {
        return id;
    }
    double getWidth() const {
        return width;
    }
    double getHeight() const {
        return height;
    }
    void setWidth(double w) {
        if (w > 0) {
            width = w;
        } else {
            cout << "Loi: Chieu rong phai lon hon 0! Gan mac dinh = 1.0" << endl;
            width = 1.0;
        }
    }
    void setHeight(double h) {
        if (h > 0) {
            height = h;
        } else {
            cout << "Loi: Chieu cao phai lon hon 0! Gan mac dinh = 1.0" << endl;
            height = 1.0;
        }
    }
    double area() const {
        return width * height;
    }
    double perimeter() const {
        return (width + height) * 2;
    }
    void display() const {
        cout << "Hinh chu nhat ID: " << getId() 
             << " | Rong: " << getWidth() 
             << " | Cao: " << getHeight() 
             << " | Dien tich: " << area() 
             << " | Chu vi: " << perimeter() << endl;
    }
};

int main() {
    Rectangle rect1(101, 4.5, 3.0);
    rect1.display();
    rect1.setWidth(5.5);
    rect1.setHeight(-2.0);
    rect1.display();
    return 0;
}