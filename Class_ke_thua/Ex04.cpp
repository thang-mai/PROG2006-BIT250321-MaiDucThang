#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class Shape {
    protected:
        string color;
    public:
        Shape(string c) : color(c) {}
        void describe() {
            cout << "Shape: " << color;
        }
        double area() {
            return 0.0;
        }
};

class Cricle : public Shape {
    private:
        double radius;
    public:
        Cricle(string c, double r) : Shape(c), radius(r) {}
        void describe() {
            Shape::describe();
            cout << "| Circle: radius = " << radius;
        }
        double area() {
            return 3.14 * radius * radius;
        }
};

class Rectangle : public Shape {
    private: 
        double width;
        double height;
    public:
        Rectangle(string c, double w, double h) : Shape(c), width(w), height(h) {}
        void describle() {
            Shape::describe();
            cout << "| Rectangle: width = " << width << ", height = " << height;
        }
        double area() {
            return width * height;
        }
};

int main() {
    Cricle c("Red", 5.0);
    Rectangle r("Blue", 4.0, 6.0);
    c.describe();
    cout << ", Area: " << c.area() << endl;
    r.describe();
    cout << ", Area: " << r.area() << endl;
    return 0;
}